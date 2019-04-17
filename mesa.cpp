#include "mesa.h"

mesa::mesa()
{

}

void mesa::sumarbote(int apuesta, jugador player){
    bote = bote + player.apostar(apuesta);
}

void mesa::repartir123(jugador player1, jugador player2, jugador player3){
    bool comprobacion = true;
    int aux = 1+rand()%52;
    while (comprobacion){
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && player3.cartas[0] != aux && player3.cartas[1] != aux){
            comprobacion = false;
        }
    }
    cartas[0] = aux;
    comprobacion = true;
    aux = 1+rand()%52;
    while (comprobacion){
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && player3.cartas[0] != aux && player3.cartas[1] != aux && cartas[0] != aux){
            comprobacion = false;
        }
    }
    cartas[1] = aux;
    comprobacion = true;
    aux = 1+rand()%52;
    while (comprobacion){
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && player3.cartas[0] != aux && player3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux){
            comprobacion = false;
        }
    }
    cartas[2] = aux;
}

void mesa::repartir4(jugador player1, jugador player2, jugador player3){
    bool comprobacion = true;
    int aux = 1+rand()%52;
    while (comprobacion){
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && player3.cartas[0] != aux && player3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux && cartas[2] != aux){
            comprobacion = false;
        }
    }
    cartas[3] = aux;
}

void mesa::repartir5(jugador player1, jugador player2, jugador player3){
    bool comprobacion = true;
    int aux = 1+rand()%52;
    while (comprobacion){
        if (player1.cartas[0] != aux && player1.cartas[1] != aux && player2.cartas[0] != aux && player2.cartas[1] != aux && player3.cartas[0] != aux && player3.cartas[1] != aux && cartas[0] != aux && cartas[1] != aux && cartas[2] != aux && cartas[3] != aux){
            comprobacion = false;
        }
    }
    cartas[4] = aux;
}

int mesa::devolverbote(){
    return bote;
}
