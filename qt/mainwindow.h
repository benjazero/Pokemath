#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <memory>

class Jugador;
class Grado;
class Pregunta;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Jugador> jugador;
    std::unique_ptr<Jugador> rival;
    std::unique_ptr<Grado> grado;
    std::unique_ptr<Pregunta> preguntaActual;

    int rachaActual;

    void iniciarCombate();
    void responderPregunta();
    void cargarPregunta();
    void actualizarEstado();
    void terminarCombate(const QString& mensaje);
    void agregarHistorial(const QString& mensaje);
};

#endif
