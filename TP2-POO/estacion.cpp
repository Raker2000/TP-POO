#include "estacion.h"
#include <qrandom.h>

Estacion::Estacion(Tablero *t)
{
    //////////////////////////////////
    /// OPTIMIZAR TODO ESTE CODIGO ///
    //////////////////////////////////

    char tiposEstaciones[4];//esto tiene que ser puntero para poder eliminarlo despues
    tiposEstaciones[0]='N';//normal
    tiposEstaciones[1]='M';//multiples
    tiposEstaciones[2]='H';//horizontales
    tiposEstaciones[3]='V';//verticales

    int seleccionEstacion;//hacer que reciba un valor aleatorio entre 0 y 4 para seleccionar el tipo de estacion

    posF = QRandomGenerator::global()->bounded(t->getFilas());
    posC = QRandomGenerator::global()->bounded(t->getColumnas());

    while(t->getTableroEnPos(posF,posC)!='0')///evita que se puedan generar 2 estaciones en el mismo lugar o encima de una ruta
    {
        posF = QRandomGenerator::global()->bounded(t->getFilas());
        posC = QRandomGenerator::global()->bounded(t->getColumnas());
    }

    t->setTablero(posF,posC,'E');//cambiar para que admita distintos tipos de estaciones


    while(t->getTableroEnPos(posF,posC)!='0')///evita que se puedan generar 2 estaciones en el mismo lugar o encima de una ruta
    {
        posF = QRandomGenerator::global()->bounded(t->getFilas());
        posC = QRandomGenerator::global()->bounded(t->getColumnas());
    }

    t->setTablero(posF,posC,'E');//cambiar para que admita distintos tipos de estaciones

    //aca hay que eliminar el vector char
}
