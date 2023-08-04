#include "juego.h"
#include <tablero.h>
#include <estacion.h>
#include <qtimer.h>
#include <qrandom.h>

Juego::Juego()
{

}

void Juego::iniciarPartida(Tablero* t)
{
    estaciones.push_back(crearEstacion(t));
    estaciones.push_back(crearEstacion(t));
    //arrancar el temporizador (una vez esté implementado)
    posXRuta = QRandomGenerator::global()->bounded(1,t->getFilas()-1);
    posYRuta = QRandomGenerator::global()->bounded(1,t->getColumnas()-1);


    t->setTablero(posXRuta,posYRuta,'X');//cambiar esto para que la primer ruta aparezca aledaña o encima a una estacion (no se cual de las 2 hay que hacer)
}

Estacion* Juego::crearEstacion(Tablero *t)
{
    Estacion* e = new Estacion(t);
    //las estaciones horizontales no pueden estar pegadas ni al techo ni al piso
    //las verticales no pueden estar pegadas a las paredes
    //no deben ser adyacentes
    return e;
}

void Juego::crearRuta(Tablero *t, char dir)
{
    //falta realizar verificacion de limites, para que no se pueda introducir una posicion invalida (si la matriz tiene x=10, x no puede ser 12)
    switch(dir)//las rutas no deben poder atravesarse entre si
    {
    case 'w':
        posXRuta--;
        t->setTablero(posXRuta,posYRuta,'X');
        break;
    case 'a':
        posYRuta--;
        t->setTablero(posXRuta,posYRuta,'X');
        break;
    case 's':
        posXRuta++;
        t->setTablero(posXRuta,posYRuta,'X');
        break;
    case 'd':
        posYRuta++;
        t->setTablero(posXRuta,posYRuta,'X');
        break;
    }

    bool todasEstacionesConectadas=true;
    for(int i=0; i<estaciones.size(); i++)
    {
        if(!estaciones[i]->estaConectada(t))//si encuentra que una estacion no esta conectada
        {
            todasEstacionesConectadas = false;
            i=estaciones.size();
        }
    }
    if(todasEstacionesConectadas)
    {
        estaciones.push_back(crearEstacion(t));
    }
}
