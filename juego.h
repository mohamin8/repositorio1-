#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <mesa.h>
#include <QTextEdit>

namespace Ui {
class juego;
}

class juego : public QMainWindow
{
    Q_OBJECT

public:
    explicit juego(QString nombre1, QString nombre2, QString nombre3, QWidget *parent = nullptr);
    ~juego();
    void turnoinicial(mesa table, jugador player1, jugador player2, jugador player3);

private:
    Ui::juego *ui;
    int jugada = 1;
};

#endif // JUEGO_H
