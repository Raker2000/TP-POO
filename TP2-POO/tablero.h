#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
private:
	int filas, columnas;
    	char** tablero;//la clase tablero contiene a la matriz tablero
public:
    Tablero(int f, int c);
	void generarTablero(int f, int c);
    	void setTablero(int f, int c, char car);
	void resetTablero();
    	void mostrarTablero();
    	char getTableroEnPos(int f, int c);
    	int getFilas();
    	int getColumnas();
};

#endif // TABLERO_H
