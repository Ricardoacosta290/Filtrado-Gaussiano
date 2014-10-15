#include "Imagen.h"

// Implementacion de las diversas funciones de la clase Imagen...

Imagen::Imagen(int numFilas, int numCols)
{    
    /* Imagen de numFilas x numCols y sus respectivos arrays*/
        
    N = numFilas;
    M = numCols;
    
    valPixel = new int *[N];

    for(int i = 0; i < N; i++)
    {
        valPixel[i] = new int [M];

        for(int j = 0; j < M; j++)
            
            valPixel[i][j] = 0;
    }
}

Imagen::~Imagen()
{  
    delete [] valPixel;
    N = M = 0;
    valPixel = NULL;
}

Imagen::Imagen(const Imagen& imgAntigua)
{
    /*Constructor copia: imgAntigua a referencia actual *this */
    
    *this = imgAntigua;
}

void Imagen::operator=(const Imagen& imgAsignada)
{
    /*OP Asignacion: imgAsignada es copiada al objeto imagen de la izquierda*/

    N = imgAsignada.N;
    M = imgAsignada.M;
    
    valPixel = new int* [N];

    for(int i = 0; i < N; i++)
    {
        valPixel[i] = new int [M];

        for(int j = 0; j < M; j++)

            valPixel[i][j] = imgAsignada.valPixel[i][j];
    }
}

/* Funciones de la clase */

void Imagen::setValPixel(int fila, int col, int valorPixel)
{
    /*set del valor de un pixel especifico*/

    valPixel[fila][col] = valorPixel;
}

int Imagen::getValPixel(int fila, int col)
{
    /*get del valor de un pixel especifico*/
    
    return valPixel[fila][col];
}

void Imagen::setInfoImagen(int numFilas, int numCols)
{
    /*set del numero de filas, columnas y grises*/

    N = numFilas;
    M = numCols;
}

void Imagen::getInfoImagen(int &numFilas, int &numCols)
{
    /*get del numero de filas, columnas y grises*/

    numFilas = N;
    numCols = M;
}