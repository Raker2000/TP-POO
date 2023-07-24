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
	void setTablero(int f, int c);
	void resetTablero();
    	char** getTablero();
};

#endif // TABLERO_H
