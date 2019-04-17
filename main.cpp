#include "mainwindow.h"
#include "juego.h"
#include <QApplication>
#include <QString>
#include "jugador.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
