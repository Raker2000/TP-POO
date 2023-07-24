#include "tablero.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Tablero::Tablero(int f, int c)
{
	generarTablero(f,c);
}

void Tablero::generarTablero(int f, int c)
{
    tablero = new char*[f];
	for(int i=0; i<f; i++)
	{
        tablero[i] = new char[c];
	}
	
	filas=f;
	columnas=c;
	
	resetTablero();//establece todas las posiciones en 0
}

char Tablero::getTableroEnPos(int f, int c)
{
    return tablero[f][c];
}

void Tablero::setTablero(int f, int c, char car)//0 (vacio),  * (camino),  — (estacion horizontal), | (estacion vertical), T (3 caminos)
{
    if(f<=filas && c<=columnas)
	{
        tablero[f][c]=car;
	}
}

void Tablero::resetTablero()
{
    for(int i=0; i<filas; i++)
	{
        for(int j=0; j<columnas; j++)
		{
            tablero[i][j]='0';
		}
    }
}

void Tablero::mostrarTablero()
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}
