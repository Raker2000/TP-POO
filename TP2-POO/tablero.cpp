#include "tablero.h"

Tablero::Tablero(int f, int c)
{
	generarTablero(f,c);
}

void Tablero::generarTablero()
{
	tablero = new int*[f];
	for(int i=0; i<f; i++)
	{
		tablero[i] = new int[c];
	}
	
	filas=f;
	columnas=c;
	
	resetTablero();//establece todas las posiciones en 0
}

int** Tablero::getTablero()
{
	return tablero;
}

void Tablero::setTablero(int f, int c)//0-vacio  1-camino  2-estacion
{
	if(f<=filas && c<=columnas
	{
		tablero[f][c]==1;
	}
}

void Tablero::resetTablero()
{
	for(int i=0; i<f; i++)
	{
		for(int j=0; j<c; j++)
		{
			tablero[i][j]=0;
		}
	}
}
