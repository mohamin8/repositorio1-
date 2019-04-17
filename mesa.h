#ifndef MESA_H
#define MESA_H
#include <vector>
#include <jugador.h>
#include <stdlib.h>

using namespace std;

class mesa
{
public:
    mesa();
    void sumarbote(int apuesta, jugador player);
    void repartir123(jugador player1, jugador player2, jugador player3);
    void repartir4(jugador player1, jugador player2, jugador player3);
    void repartir5(jugador player1, jugador player2, jugador player3);
    int devolverbote();
private:
    int bote = 0;
    vector <int> cartas{5};
};

#endif // MESA_H
