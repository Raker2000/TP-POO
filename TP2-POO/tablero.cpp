#include "tablero.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Tablero::Tablero()
{

}

Tablero::Tablero(int f, int c)
{
    generarTablero(f+2,c+2);///el tablero generado es mas grande para generar un margen alrededor en donde las posiciones sean validas
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

int Tablero::getFilas()
{
    return filas;
}

int Tablero::getColumnas()
{
    return columnas;
}

void Tablero::setTablero(int f, int c, char car)
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
    system("CLS");
    for(int i=1; i<filas-1; i++)
    {
        for(int j=1; j<columnas-1; j++)
        {
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
}
