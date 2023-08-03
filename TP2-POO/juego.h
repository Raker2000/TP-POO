#ifndef JUEGO_H
#define JUEGO_H
#include <tablero.h>
#include <estacion.h>

class Juego
{
private:
    Estacion* estaciones;//vector de estaciones, deben estar referenciadas para poder eliminarlas mas tarde
    int posXRuta;
    int posYRuta;
public:
    Juego();
    void iniciarPartida(Tablero* t);
    void crearEstacion(Tablero* t);
    void crearRuta(Tablero* t, char dir);
    //falta crear temporizador
};

#endif // JUEGO_H
