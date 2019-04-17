#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <vector>
#include <QString>
#include <time.h>

using namespace std;

class jugador{

public:
    jugador();
    void nombrar(QString nuevonombre);
    int apostar(int subida);
    vector <int> cartas{2};
    void obtenercartas(jugador player1, jugador player2);
    int devolverdinero();
    int devolverapuesta();
    QString devolvernombre();
    bool devolvereliminado();

private:
    QString nombre;
    int dinero;
    int apuesta;
    bool eliminado;

};

#endif // JUGADOR_H
