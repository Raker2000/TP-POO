#include "estacion.h"
#include <qrandom.h>
#include <iostream>

bool posicionValida(Tablero* t, int posF, int posC, char tip)
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
    if(tip=='H' && (posC>=t->getColumnas()-1 || posC==1))///si las estaciones horizontales estan pegadas a una pared
    {
        valida = false;
    }
    if(tip=='V' && (posF>=t->getFilas()-1 || posF==1))///si las estaciones verticales estan pegadas a el techo o piso
    {
        valida = false;
    }
    return valida;
}

Estacion::Estacion(Tablero *t)
{
    //////////////////////////////////
    /// OPTIMIZAR TODO ESTE CODIGO ///
    //////////////////////////////////

    char * tiposEstaciones= new char[4];
    tiposEstaciones[0]='N';//normal
    tiposEstaciones[1]='M';//multiples
    tiposEstaciones[2]='H';//horizontales
    tiposEstaciones[3]='V';//verticales

    int seleccionEstacion = QRandomGenerator::global()->bounded(5);

    posF = QRandomGenerator::global()->bounded(1,t->getFilas()-1);///debe estar dentro del margen jugable
    posC = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);

    tipo = tiposEstaciones[seleccionEstacion];
    while(t->getTableroEnPos(posF,posC)!='0' && posicionValida(t,posF,posC,tipo))///evita que se puedan generar 2 estaciones en el mismo lugar o encima de una ruta
    {
        posF = QRandomGenerator::global()->bounded(1,t->getFilas()-1);
        posC = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);
    }

    conectada = false;
    t->setTablero(posF,posC,tiposEstaciones[seleccionEstacion]);


    delete[] tiposEstaciones;
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
