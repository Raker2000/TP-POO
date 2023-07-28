#include "estacion.h"
#include <qrandom.h>

Estacion::Estacion(Tablero *t)
{
    posF = QRandomGenerator::global()->bounded(t->getFilas());
    posC = QRandomGenerator::global()->bounded(t->getColumnas());


    t->setTablero(posF,posC,'E');//cambiar para que admita distintos tipos de estaciones
}
