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
    crearEstacion(t);
    //arrancar el temporizador (una vez esté implementado)
    posXRuta = QRandomGenerator::global()->bounded(t->getFilas());
    posYRuta = QRandomGenerator::global()->bounded(t->getColumnas());
    t->setTablero(posXRuta,posYRuta,'X');//cambiar esto para que la primer ruta aparezca aledaña o encima a una estacion (no se cual de las 2 hay que hacer)
}

void Juego::crearEstacion(Tablero *t)
{
    Estacion* e = new Estacion(t);//se necesita almacenar las instancias para eliminarlas despues
    //las estaciones horizontales no pueden estar pegadas ni al techo ni al piso
    //las verticales no pueden estar pegadas a las paredes
    //no deben ser adyacentes
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
}
