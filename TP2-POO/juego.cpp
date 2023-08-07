#include "juego.h"
#include <tablero.h>
#include <estacion.h>
#include <qtimer.h>
#include <qrandom.h>
#include <iostream>

Juego::Juego()
{
    tiempo = new QTimer(this);
    tiempo->setInterval(10000); //10000 milisegundos igual a 10 segundos. No recuerdo si se estableció un tiempo previo o si lo definíamos nosotros
    connect(tiempo, SIGNAL(timeout()), this, SLOT(temporizador()));
}

void Juego::iniciarPartida(Tablero* t)
{
    estaciones.clear();
    t->resetTablero();
    estaciones.push_back(crearEstacion(t));
    estaciones.push_back(crearEstacion(t));
    //tiempo->start();
    posXRuta = QRandomGenerator::global()->bounded(1,t->getFilas()-1);
    posYRuta = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);


    t->setTablero(posXRuta,posYRuta,'X');//cambiar esto para que la primer ruta aparezca aledaña o encima a una estacion (no se cual de las 2 hay que hacer)
}

Estacion* Juego::crearEstacion(Tablero *t)
{
    Estacion* e = new Estacion(t);
    return e;
}

void Juego::crearRuta(Tablero *t, char dir)
{
    //falta realizar verificacion de limites, para que no se pueda introducir una posicion invalida (si la matriz tiene x=10, x no puede ser 12)
    switch(dir)
    {
    case 'w':
        if(t->getTableroEnPos(posXRuta-1,posYRuta)=='0')
        {
            posXRuta--;
            t->setTablero(posXRuta,posYRuta,'X');
        }
        break;
    case 'a':
        if(t->getTableroEnPos(posXRuta,posYRuta-1)=='0')
        {
            posYRuta--;
            t->setTablero(posXRuta,posYRuta,'X');
        }
        break;
    case 's':
        if(t->getTableroEnPos(posXRuta+1,posYRuta)=='0')
        {
            posXRuta++;
            t->setTablero(posXRuta,posYRuta,'X');
        }
        break;
    case 'd':
        if(t->getTableroEnPos(posXRuta,posYRuta+1)=='0')
        {
            posYRuta++;
            t->setTablero(posXRuta,posYRuta,'X');
        }
        break;
    }

    bool todasEstacionesConectadas=true;
    for(int i=0; i<estaciones.size(); i++)
    {
        if(!estaciones[i]->estaConectada(t))///si encuentra que una estacion no esta conectada
        {
            todasEstacionesConectadas = false;
            i=estaciones.size();
        }
    }
    if(todasEstacionesConectadas)
    {
        estaciones.push_back(crearEstacion(t));
    }

    revisarVictoria(t);
}

void Juego::temporizador(){ //falta lo de finalizar el juego cuando se termino el tiempo, por ahora solo lanza un mensaje
    std::cout << "¡Tiempo finalizado!" << std::endl;
    estaciones.clear();
    tiempo->stop();
}

bool Juego::revisarVictoria(Tablero *t)
{
    bool ganaste=true;

    for(int i=0; i<t->getFilas(); i++)
    {
        for(int j=0; j<t->getColumnas(); j++)
        {
            if(t->getTableroEnPos(i,j)=='0')
            {
                ganaste = false;
            }
        }
    }

    if(ganaste)
    {
        estaciones.clear();
        std::cout<<"Ganaste!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    }

    return ganaste;
}
