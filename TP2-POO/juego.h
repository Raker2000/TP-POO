#ifndef JUEGO_H
#define JUEGO_H
#include <tablero.h>
#include <estacion.h>
#include <qvector.h>

class Juego
{
private:
    QVector<Estacion*> estaciones;
    int posXRuta;
    int posYRuta;
public:
    Juego();
    void iniciarPartida(Tablero* t);
    Estacion* crearEstacion(Tablero* t);
    void crearRuta(Tablero* t, char dir);

    //falta crear temporizador
};

#endif // JUEGO_H
