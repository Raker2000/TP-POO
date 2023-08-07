#ifndef JUEGO_H
#define JUEGO_H
#include <tablero.h>
#include <estacion.h>
#include <qvector.h>
#include <QTimer>

class Juego
{
private:
    QVector<Estacion*> estaciones;
    int posXRuta;
    int posYRuta;
    QTimer* tiempo;
public:
    Juego();
    void iniciarPartida(Tablero* t);
    Estacion* crearEstacion(Tablero* t);
    void crearRuta(Tablero* t, char dir);
    void temporizador();
    bool revisarVictoria(Tablero* t);
};

#endif // JUEGO_H
