#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nombre1_textChanged(const QString &arg1)
{
    nombre1 = arg1;
}

void MainWindow::on_nombre2_textChanged(const QString &arg1)
{
    nombre2 = arg1;
}

void MainWindow::on_nombre3_textChanged(const QString &arg1)
{
    nombre3 = arg1;
}

void MainWindow::openjuego()
{
    juegowindow = new juego(nombre1, nombre2, nombre3);
    juegowindow->show();

}

void MainWindow::on_comenzar_clicked()
{
    openjuego();
    close();
}
