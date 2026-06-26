#include <QApplication>
#include <cstdlib>
#include <ctime>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    QApplication app(argc, argv);

    MainWindow ventana;
    ventana.show();

    return app.exec();
}