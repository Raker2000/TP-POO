#ifndef ESTACION_H
#define ESTACION_H
#include <tablero.h>

class Estacion:public Tablero
{
private:
    int posF;
    int posC;
    char tipo;
public:
    Estacion(Tablero *t);
};

#endif // ESTACION_H
