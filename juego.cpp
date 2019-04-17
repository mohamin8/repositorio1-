#include "juego.h"
#include "ui_juego.h"
#include "QMessageBox"
#include "mainwindow.h"
#include <jugador.h>

juego::juego(QString nombre1, QString nombre2, QString nombre3, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::juego)
{
    ui->setupUi(this);
//    QMessageBox::information(this, "Mensaje", "Pasadle el ordenador al primer jugador");
    QMessageBox::information(this,"Mensaje",QString("Pasadle el ordenador a %1").arg(nombre1));
    ui->tu_apuesta->setReadOnly(true);
    ui->tu_dinero->setReadOnly(true);
    ui->bote_actual->setReadOnly(true);
    ui->nombre->setReadOnly(true);
    jugador jugador1;
    jugador jugador2;
    jugador jugador3;
    jugador1.nombrar(nombre1);
    jugador2.nombrar(nombre2);
    jugador3.nombrar(nombre3);
    mesa mesa;
    turnoinicial(mesa, jugador1, jugador2, jugador3);
    jugador1.obtenercartas(jugador2, jugador3);
    jugador2.obtenercartas(jugador1,jugador3);
    jugador3.obtenercartas(jugador1, jugador2);
}

juego::~juego()
{
    delete ui;
}

void juego::turnoinicial(mesa table, jugador player1, jugador player2, jugador player3){
    if (jugada % 3 == 0){
        table.sumarbote(25,player1);
        table.sumarbote(50,player2);
        ui->tu_apuesta->setText(QString::number(player3.devolverapuesta()));
        ui->tu_dinero->setText(QString::number(player3.devolverdinero()));
        ui->bote_actual->setText(QString::number(table.devolverbote()));
        ui->nombre->setText(player3.devolvernombre());
        jugada++;
    }
    else if(jugada % 2 == 0){
        table.sumarbote(25,player3);
        table.sumarbote(50,player1);
        ui->tu_apuesta->setText(QString::number(player2.devolverapuesta()));
        ui->tu_dinero->setText(QString::number(player2.devolverdinero()));
        ui->bote_actual->setText(QString::number(table.devolverbote()));
        ui->nombre->setText(player2.devolvernombre());
        jugada++;
    }
    else{
        table.sumarbote(25,player2);
        table.sumarbote(50,player3);
        ui->tu_apuesta->setText(QString::number(player1.devolverapuesta()));
        ui->tu_dinero->setText(QString::number(player1.devolverdinero()));
        ui->bote_actual->setText(QString::number(table.devolverbote()));
        ui->nombre->setText(player1.devolvernombre());
        jugada++;
    }
}
