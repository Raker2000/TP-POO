#include "estacion.h"
#include <qrandom.h>
#include <iostream>

bool posicionValida(Tablero* t, int posF, int posC)
{
    bool valida=true;
    for(int i=-1; i<2; i++)
    {
        for(int j=-1; j<2; j++)
        {
            if(t->getTableroEnPos(posF+i,posC+j)!='0' && t->getTableroEnPos(posF+i,posC+j)!='X')
            {
                valida=false;
                i=2; j=2;
            }
        }
    }
    return valida;
}

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

    int seleccionEstacion = QRandomGenerator::global()->bounded(4);

    posF = QRandomGenerator::global()->bounded(1,t->getFilas()-1);///debe estar dentro del margen jugable
    posC = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);

    while(t->getTableroEnPos(posF,posC)!='0' && posicionValida(t,posF,posC))///evita que se puedan generar 2 estaciones en el mismo lugar o encima de una ruta
    {
        posF = QRandomGenerator::global()->bounded(1,t->getFilas()-1);
        posC = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);
    }

    conectada = false;
    t->setTablero(posF,posC,tiposEstaciones[seleccionEstacion]);
    tipo = tiposEstaciones[seleccionEstacion];

    //aca hay que eliminar el vector char
}

bool Estacion::estaConectada(Tablero *t)
{
    //esto aveces revisa en posiciones invalidas y crashea el programa
    if((tipo=='N' || tipo=='M') && (t->getTableroEnPos(posF-1,posC)=='X' || t->getTableroEnPos(posF+1,posC)=='X' || t->getTableroEnPos(posF,posC-1)=='X' || t->getTableroEnPos(posF,posC+1)=='X'))
    {
        t->setTablero(posF,posC,'C');
        conectada=true;
    }
    if(tipo=='H' && (t->getTableroEnPos(posF,posC-1)=='X' || t->getTableroEnPos(posF,posC+1)=='X'))
    {
        t->setTablero(posF,posC,'C');
        conectada=true;
    }
    if(tipo=='V' && (t->getTableroEnPos(posF-1,posC)=='X' || t->getTableroEnPos(posF+1,posC)=='X'))
    {
        t->setTablero(posF,posC,'C');
        conectada=true;
    }
    return conectada;
}
