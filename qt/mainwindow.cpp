#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Jugador.h"
#include "Grado.h"
#include "Grado1.h"
#include "Grado2.h"
#include "Grado3.h"
#include "Pregunta.h"

#include <QMessageBox>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    rachaActual(0)
{
    ui->setupUi(this);

    setWindowTitle("Pokemath");

    ui->progressBarJugador->setRange(0, 100);
    ui->progressBarRival->setRange(0, 100);

    ui->progressBarJugador->setValue(100);
    ui->progressBarRival->setValue(100);

    ui->progressBarJugador->setTextVisible(false);
    ui->progressBarRival->setTextVisible(false);

    ui->labelVidaJugador->setText("Jugador: 100 HP");
    ui->labelVidaRival->setText("Rival: 100 HP");

    ui->labelPregunta->setText("Ingresa los nombres y presiona Iniciar combate.");

    ui->btnResponder->setEnabled(false);
    ui->lineEditRespuesta->setEnabled(false);

    ui->labelRespuesta2->hide();
    ui->lineEditRespuesta2->hide();
    ui->lineEditRespuesta2->setEnabled(false);

    ui->lineEditRespuesta->setValidator(
        new QDoubleValidator(-9999.0, 9999.0, 2, this)
        );

    ui->lineEditRespuesta2->setValidator(
        new QDoubleValidator(-9999.0, 9999.0, 2, this)
        );

    connect(ui->btnIniciar, &QPushButton::clicked,
            this, &MainWindow::iniciarCombate);

    connect(ui->btnResponder, &QPushButton::clicked,
            this, &MainWindow::responderPregunta);

    connect(ui->lineEditRespuesta, &QLineEdit::returnPressed,
            this, &MainWindow::responderPregunta);

    connect(ui->lineEditRespuesta2, &QLineEdit::returnPressed,
            this, &MainWindow::responderPregunta);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniciarCombate()
{
    QString nombreJugador = ui->lineEditJugador->text().trimmed();
    QString nombreRival = ui->lineEditRival->text().trimmed();

    if (nombreJugador.isEmpty() || nombreRival.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos",
                             "Debes ingresar el nombre del jugador y del rival.");
        return;
    }

    jugador = std::make_unique<Jugador>(nombreJugador.toStdString());
    rival = std::make_unique<Jugador>(nombreRival.toStdString());

    switch (ui->comboDificultad->currentIndex()) {
    case 0:
        grado = std::make_unique<Grado1>();
        break;

    case 1:
        grado = std::make_unique<Grado2>();
        break;

    case 2:
        grado = std::make_unique<Grado3>();
        break;

    default:
        grado = std::make_unique<Grado1>();
        break;
    }

    rachaActual = 0;

    ui->textEditHistorial->clear();
    ui->btnIniciar->setText("Reiniciar combate");

    ui->btnResponder->setEnabled(true);
    ui->lineEditRespuesta->setEnabled(true);

    agregarHistorial("Comenzó el combate entre " +
                     nombreJugador + " y " + nombreRival + ".");

    agregarHistorial("Dificultad seleccionada: " +
                     ui->comboDificultad->currentText());

    actualizarEstado();
    cargarPregunta();
}

void MainWindow::cargarPregunta()
{
    if (!grado) {
        return;
    }

    preguntaActual = grado->generarPregunta();

    ui->labelPregunta->setText(
        QString::fromStdString(preguntaActual->getEnunciado())
        );

    bool requiereDosRespuestas = preguntaActual->cantidadRespuestas() == 2;

    ui->labelRespuesta2->setVisible(requiereDosRespuestas);
    ui->lineEditRespuesta2->setVisible(requiereDosRespuestas);
    ui->lineEditRespuesta2->setEnabled(requiereDosRespuestas);

    ui->lineEditRespuesta->clear();
    ui->lineEditRespuesta2->clear();

    if (requiereDosRespuestas) {
        ui->lineEditRespuesta->setPlaceholderText("Valor de x");
        ui->lineEditRespuesta2->setPlaceholderText("Valor de y");
    } else {
        ui->lineEditRespuesta->setPlaceholderText("Escribe tu respuesta");
    }

    ui->lineEditRespuesta->setFocus();
}

void MainWindow::responderPregunta()
{
    if (!preguntaActual || !jugador || !rival) {
        return;
    }

    bool respuesta1Valida = false;
    bool respuesta2Valida = true;

    float respuesta1 = ui->lineEditRespuesta->text().toFloat(&respuesta1Valida);
    float respuesta2 = 0.0f;

    bool requiereDosRespuestas = preguntaActual->cantidadRespuestas() == 2;

    if (requiereDosRespuestas) {
        respuesta2 = ui->lineEditRespuesta2->text().toFloat(&respuesta2Valida);
    }

    if (!respuesta1Valida || !respuesta2Valida) {
        QMessageBox::warning(this, "Respuesta inválida",
                             "Ingresa una respuesta numérica válida.");
        return;
    }

    bool acerto = preguntaActual->verificarRespuestas(respuesta1, respuesta2);

    if (acerto) {
        rachaActual++;

        float danio = 20.0f;

        if (rachaActual >= 3) {
            danio = 40.0f;
            agregarHistorial("¡Racha de " + QString::number(rachaActual) +
                             "! Golpe doble.");
        }

        rival->recibirDanio(danio);

        agregarHistorial("Respuesta correcta. Atacas con " +
                         QString::number(static_cast<int>(danio)) +
                         " de daño.");

    } else {
        if (rachaActual > 0) {
            agregarHistorial("Perdiste tu racha de " +
                             QString::number(rachaActual) + ".");
        }

        rachaActual = 0;
        jugador->recibirDanio(20.0f);

        agregarHistorial("Respuesta incorrecta. Recibes 20 de daño.");
    }

    actualizarEstado();

    if (!rival->estaVivo()) {
        jugador->agregarVictoria();

        terminarCombate("¡Ganaste el combate! " +
                        QString::fromStdString(jugador->getNombre()) +
                        " derrotó a " +
                        QString::fromStdString(rival->getNombre()) + ".");

        return;
    }

    if (!jugador->estaVivo()) {
        terminarCombate("Perdiste el combate. " +
                        QString::fromStdString(rival->getNombre()) +
                        " ganó la batalla.");

        return;
    }

    cargarPregunta();
}

void MainWindow::actualizarEstado()
{
    if (!jugador || !rival) {
        return;
    }

    int vidaJugador = static_cast<int>(jugador->getVida());
    int vidaRival = static_cast<int>(rival->getVida());

    ui->labelVidaJugador->setText(
        QString::fromStdString(jugador->getNombre()) +
        ": " + QString::number(vidaJugador) + " HP"
        );

    ui->labelVidaRival->setText(
        QString::fromStdString(rival->getNombre()) +
        ": " + QString::number(vidaRival) + " HP"
        );

    ui->progressBarJugador->setValue(vidaJugador);
    ui->progressBarRival->setValue(vidaRival);
}

void MainWindow::terminarCombate(const QString& mensaje)
{
    agregarHistorial(mensaje);

    ui->btnResponder->setEnabled(false);
    ui->lineEditRespuesta->setEnabled(false);
    ui->lineEditRespuesta2->setEnabled(false);

    ui->labelRespuesta2->hide();
    ui->lineEditRespuesta2->hide();

    ui->labelPregunta->setText(
        "Combate terminado. Presiona Reiniciar combate para jugar otra vez."
        );

    preguntaActual.reset();

    QMessageBox::information(this, "Combate terminado", mensaje);
}

void MainWindow::agregarHistorial(const QString& mensaje)
{
    ui->textEditHistorial->append("• " + mensaje);
}