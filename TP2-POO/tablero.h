#ifndef TABLERO_H
#define TABLERO_H


class Tablero
{
private:
	int filas, columnas;
	int** tablero;//la clase tablero contiene a la matriz tablero
public:
    Tablero();
	void generarTablero(int f, int c);
	void setTablero(int f, int c);
	void resetTablero();
	int** getTablero();
};

#endif // TABLERO_H
