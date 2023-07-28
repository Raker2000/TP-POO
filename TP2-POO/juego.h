#ifndef JUEGO_H
#define JUEGO_H
#include <tablero.h>
#include <estacion.h>

class Juego
{
private:
    Estacion* estaciones;//vector de estaciones, deben estar referenciadas para poder eliminarlas mas tarde
public:
    Juego();
    void iniciarPartida();
};

#endif // JUEGO_H
