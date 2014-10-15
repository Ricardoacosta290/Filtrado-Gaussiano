#ifndef CSTDLIB_H
  #include<cstdlib>
#endif

#ifndef IMAGEN_H
#define IMAGEN_H

class Imagen
{

  public:

    /* Constructores, destructor, operadores */

    Imagen(int numFilas, int numCols); //ok

    ~Imagen(); //ok
    
    Imagen(const Imagen& imgAntigua); // ok

    void operator=(const Imagen& imgAsignada); //ok


    
    /* Funciones de la clase */

    void setValPixel(int fila, int col, int valorPixel); //ok

    int getValPixel(int fila, int col); //ok

    void setInfoImagen(int numFilas, int numCols); //ok

    void getInfoImagen(int &numFilas, int &numCols); //ok
   

  private:
    int N; // N Filas
    int M; // M Columnas
    int **valPixel; // Array 2D para albergar los pixeles.
};

#endif