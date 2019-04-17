#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "juego.h"
#include "jugador.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString nombre1;
    QString nombre2;
    QString nombre3;

public slots:
    void openjuego();

private slots:

    void on_nombre1_textChanged(const QString &arg1);

    void on_comenzar_clicked();

    void on_nombre2_textChanged(const QString &arg1);

    void on_nombre3_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    juego *juegowindow;
};

#endif // MAINWINDOW_H
