#ifndef ESTACION_H
#define ESTACION_H
#include <tablero.h>

class Estacion:public Tablero
{
private:
    int posF;
    int posC;
    char tipo;
    bool conectada; ///para saber cuando está conectada
public:
    Estacion(Tablero *t);
    bool estaConectada(Tablero* t);
};

#endif // ESTACION_H
