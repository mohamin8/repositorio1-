#include "juego.h"
#include "ui_juego.h"
#include "QMessageBox"
#include "mainwindow.h"
#include <jugador.h>

juego::juego(QString nombre1, QString nombre2, QString nombre3, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::juego)
{
    QMessageBox::information(this,"Mensaje",QString("Pasadle el ordenador a %1").arg(nombre1));
    ui->setupUi(this);
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
}

juego::~juego()
{
    delete ui;
}

void juego::turnoinicial(mesa table, jugador player1, jugador player2, jugador player3){
    if (player1.devolvereliminado()){
        player2.obtenercartas(player1,player3);
        player3.obtenercartas(player1,player2);
        if (jugada == 3){
            table.sumarbote(25,player3);
            table.sumarbote(50,player2);
            ui->tu_apuesta->setText(QString::number(player3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player3.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player3.devolvernombre());
            jugada = 2;
        }
        else {
            table.sumarbote(25,player2);
            table.sumarbote(50,player3);
            ui->tu_apuesta->setText(QString::number(player2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player2.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player2.devolvernombre());
            jugada = 3;
        }
    }
    else if (player2.devolvereliminado()){
        player1.obtenercartas(player2,player3);
        player3.obtenercartas(player1,player2);
        if (jugada == 1){
            table.sumarbote(25,player1);
            table.sumarbote(50,player3);
            ui->tu_apuesta->setText(QString::number(player1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player1.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player1.devolvernombre());
            jugada = 3;
        }
        else {
            table.sumarbote(25,player3);
            table.sumarbote(50,player1);
            ui->tu_apuesta->setText(QString::number(player3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player3.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player3.devolvernombre());
            jugada = 1;
        }
    }
    else if (player3.devolvereliminado()){
        player1.obtenercartas(player2,player3);
        player2.obtenercartas(player1,player3);
        if (jugada == 2){
            table.sumarbote(25,player2);
            table.sumarbote(50,player1);
            ui->tu_apuesta->setText(QString::number(player2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player2.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player2.devolvernombre());
            jugada = 1;
        }
        else {
            table.sumarbote(25,player1);
            table.sumarbote(50,player2);
            ui->tu_apuesta->setText(QString::number(player1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player1.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player1.devolvernombre());
            jugada = 2;
        }
    }
    else {
        player1.obtenercartas(player2,player3);
        player2.obtenercartas(player1,player3);
        player3.obtenercartas(player1,player2);
        if (jugada == 3){
            table.sumarbote(25,player1);
            table.sumarbote(50,player2);
            ui->tu_apuesta->setText(QString::number(player3.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player3.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player3.devolvernombre());
            jugada = 1;
        }
        else if(jugada == 2){
            table.sumarbote(25,player3);
            table.sumarbote(50,player1);
            ui->tu_apuesta->setText(QString::number(player2.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player2.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player2.devolvernombre());
            jugada = 3;
        }
        else{
            table.sumarbote(25,player2);
            table.sumarbote(50,player3);
            ui->tu_apuesta->setText(QString::number(player1.devolverapuesta()));
            ui->tu_dinero->setText(QString::number(player1.devolverdinero()));
            ui->bote_actual->setText(QString::number(table.devolverbote()));
            ui->nombre->setText(player1.devolvernombre());
            QPixmap pix1(":/imagenes/10picas.png");
            ui->mano1->setPixmap(pix1);
            mostrarmano(player1.cartas[0], player1.cartas[1]);
            jugada = 2;
        }
    }
}

void juego::mostrarmano(int carta1, int carta2){
    switch (carta1) {
    case 1: ui->mano1->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mano1->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mano1->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mano1->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mano1->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mano1->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mano1->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mano1->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mano1->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mano1->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mano1->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mano1->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mano1->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mano1->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mano1->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mano1->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mano1->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mano1->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mano1->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mano1->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mano1->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mano1->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mano1->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mano1->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mano1->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mano1->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mano1->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mano1->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mano1->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mano1->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mano1->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mano1->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mano1->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mano1->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mano1->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mano1->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mano1->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mano1->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mano1->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mano1->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mano1->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mano1->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mano1->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mano1->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mano1->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mano1->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mano1->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mano1->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mano1->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mano1->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mano1->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mano1->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mano1->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }


    switch (carta2) {
    case 1: ui->mano2->setPixmap(QPixmap(":/imagenes/1corazones.png"));
        break;
    case 2: ui->mano2->setPixmap(QPixmap(":/imagenes/2corazones.png"));
        break;
    case 3: ui->mano2->setPixmap(QPixmap(":/imagenes/3corazones.png"));
        break;
    case 4: ui->mano2->setPixmap(QPixmap(":/imagenes/4corazones.png"));
        break;
    case 5: ui->mano2->setPixmap(QPixmap(":/imagenes/5corazones.png"));
        break;
    case 6: ui->mano2->setPixmap(QPixmap(":/imagenes/6corazones.png"));
        break;
    case 7: ui->mano2->setPixmap(QPixmap(":/imagenes/7corazones.png"));
        break;
    case 8: ui->mano2->setPixmap(QPixmap(":/imagenes/8corazones.png"));
        break;
    case 9: ui->mano2->setPixmap(QPixmap(":/imagenes/9corazones.png"));
        break;
    case 10: ui->mano2->setPixmap(QPixmap(":/imagenes/10corazones.png"));
        break;
    case 11: ui->mano2->setPixmap(QPixmap(":/imagenes/Jcorazones.png"));
        break;
    case 12: ui->mano2->setPixmap(QPixmap(":/imagenes/Qcorazones.png"));
        break;
    case 13: ui->mano2->setPixmap(QPixmap(":/imagenes/Kcorazones.png"));
        break;
    case 14: ui->mano2->setPixmap(QPixmap(":/imagenes/1picas.png"));
        break;
    case 15: ui->mano2->setPixmap(QPixmap(":/imagenes/2picas.png"));
        break;
    case 16: ui->mano2->setPixmap(QPixmap(":/imagenes/3picas.png"));
        break;
    case 17: ui->mano2->setPixmap(QPixmap(":/imagenes/4picas.png"));
        break;
    case 18: ui->mano2->setPixmap(QPixmap(":/imagenes/5picas.png"));
        break;
    case 19: ui->mano2->setPixmap(QPixmap(":/imagenes/6picas.png"));
        break;
    case 20: ui->mano2->setPixmap(QPixmap(":/imagenes/7picas.png"));
        break;
    case 21: ui->mano2->setPixmap(QPixmap(":/imagenes/8picas.png"));
        break;
    case 22: ui->mano2->setPixmap(QPixmap(":/imagenes/9picas.png"));
        break;
    case 23: ui->mano2->setPixmap(QPixmap(":/imagenes/10picas.png"));
        break;
    case 24: ui->mano2->setPixmap(QPixmap(":/imagenes/Jpicas.png"));
        break;
    case 25: ui->mano2->setPixmap(QPixmap(":/imagenes/Qpicas.png"));
        break;
    case 26: ui->mano2->setPixmap(QPixmap(":/imagenes/Kpicas.png"));
        break;
    case 27: ui->mano2->setPixmap(QPixmap(":/imagenes/1rombos.png"));
        break;
    case 28: ui->mano2->setPixmap(QPixmap(":/imagenes/2rombos.png"));
        break;
    case 29: ui->mano2->setPixmap(QPixmap(":/imagenes/3rombos.png"));
        break;
    case 30: ui->mano2->setPixmap(QPixmap(":/imagenes/4rombos.png"));
        break;
    case 31: ui->mano2->setPixmap(QPixmap(":/imagenes/5rombos.png"));
        break;
    case 32: ui->mano2->setPixmap(QPixmap(":/imagenes/6rombos.png"));
        break;
    case 33: ui->mano2->setPixmap(QPixmap(":/imagenes/7rombos.png"));
        break;
    case 34: ui->mano2->setPixmap(QPixmap(":/imagenes/8rombos.png"));
        break;
    case 35: ui->mano2->setPixmap(QPixmap(":/imagenes/9rombos.png"));
        break;
    case 36: ui->mano2->setPixmap(QPixmap(":/imagenes/10rombos.png"));
        break;
    case 37: ui->mano2->setPixmap(QPixmap(":/imagenes/Jrombos.png"));
        break;
    case 38: ui->mano2->setPixmap(QPixmap(":/imagenes/Qrombos.png"));
        break;
    case 39: ui->mano2->setPixmap(QPixmap(":/imagenes/Krombos.png"));
        break;
    case 40: ui->mano2->setPixmap(QPixmap(":/imagenes/1trebol.png"));
        break;
    case 41: ui->mano2->setPixmap(QPixmap(":/imagenes/2trebol.png"));
        break;
    case 42: ui->mano2->setPixmap(QPixmap(":/imagenes/3trebol.png"));
        break;
    case 43: ui->mano2->setPixmap(QPixmap(":/imagenes/4trebol.png"));
        break;
    case 44: ui->mano2->setPixmap(QPixmap(":/imagenes/5trebol.png"));
        break;
    case 45: ui->mano2->setPixmap(QPixmap(":/imagenes/6trebol.png"));
        break;
    case 46: ui->mano2->setPixmap(QPixmap(":/imagenes/7trebol.png"));
        break;
    case 47: ui->mano2->setPixmap(QPixmap(":/imagenes/8trebol.png"));
        break;
    case 48: ui->mano2->setPixmap(QPixmap(":/imagenes/9trebol.png"));
        break;
    case 49: ui->mano2->setPixmap(QPixmap(":/imagenes/10trebol.png"));
        break;
    case 50: ui->mano2->setPixmap(QPixmap(":/imagenes/Jtrebol.png"));
        break;
    case 51: ui->mano2->setPixmap(QPixmap(":/imagenes/Qtrebol.png"));
        break;
    case 52: ui->mano2->setPixmap(QPixmap(":/imagenes/Ktrebol.png"));
        break;
    default: ui->mano2->setPixmap(QPixmap(":/imagenes/carta vuelta.png"));
        break;
    }
}
