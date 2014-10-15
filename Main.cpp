/*
    Badilla Nelson.
    Fernandez Jose Manuel.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <string>

#include "Imagen.h"

using namespace std;

// Variable global para almacenar los diversos valores del histograma
int valoresHistograma[256] = {0};

// Variable global para almacenar la longitud de la cadena del nombre de archivo de entrada...
int longitudCadena;

// Variable global para guardar el nombre del archivo para la salida...
string nombreArchivo;

// Funciones que dan solucion a los 6 ptos requeridos.

int leerImagen(char[], Imagen&);

int escribirImagen(char[], char[], Imagen&);

void negarImagen(Imagen&);

void voltearImagen(Imagen&);

void histograma(char[], Imagen&);

void nivelesGris(Imagen&);

int valorGris(int);

void equalizarHistograma(Imagen&);

double equalizar(int, int);

int menu();

// Cuerpo principal..

int main(int argc, char *argv[])
{

    /* Si no se provee al ejecutable de los parametros necesarios como argumentos por la CLI
       el programa aborta y no continua ya que necesita del .INF y el .RAW */

            if(argc < 3)
            {
                cout << "\nDebes proveer como parametros al ejecutable los siguientes archivos: " << endl;
                cout << "\n\tIMG_Entrada.inf IMG_Entrada.raw\n" << endl;
                exit(1);
            }

    /* Fin Condicion 

    /* Lectura del archivo.INF para obtener N y M */

            ifstream ifs_inf;
            
            int N, M;

            ifs_inf.open(argv[1], ios::in | ios::binary);

            if(!ifs_inf) 
            {
                cout << "No se puede abrir archivo INF: " << argv[1] << endl;
                exit(1);
            }

            ifs_inf >> M >> N; // Leer filas y columnas especificadas en el .inf

            ifs_inf.close();

    /* Fin lectura */

    /* Operaciones varias sobre el nombre que tendran los .raw y .inf de salida  */

            nombreArchivo = argv[2];

            nombreArchivo.erase(nombreArchivo.rfind("."));

    /* Fin Operaciones */

    /* Creacion de la imagen de dimension N*M obtenidos del .inf leido en la seccion anterior.. 
       Para su posterior lectura en un objeto imagen sobre el que se realizaran las diversas OP's */
            
            int op;

            Imagen imagen(N, M);
            
            leerImagen(argv[2], imagen);       

            do
            {
                op = menu();
                
                getchar();
                system("clear");
                
                switch(op)
                {
                  case 1:
                  {
                    string raw(nombreArchivo), inf(nombreArchivo);
                    Imagen imgNegada(imagen);
                    
                    raw += "_n.raw";
                    inf += "_n.inf";

                    longitudCadena = raw.length();

                    char *salidaRaw = new char[ longitudCadena + 1 ];
                    char *salidaInf = new char[ longitudCadena + 1 ];

                    raw.copy( salidaRaw, longitudCadena, 0 );
                    salidaRaw[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    inf.copy( salidaInf, longitudCadena, 0 );
                    salidaInf[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe han generado los correspondientes archivos de salida: " << endl;
                    cout << "\n\t1: " << raw << endl;
                    cout << "\t2: " << inf << endl;

                    negarImagen(imgNegada);
                    escribirImagen(salidaRaw, salidaInf, imgNegada);

                    delete [] salidaRaw;
                    delete [] salidaInf;

                  }break;

                  case 2:
                  {
                    string raw(nombreArchivo), inf(nombreArchivo);
                    Imagen imgFlip(imagen);
                    
                    raw += "_fh.raw";
                    inf += "_fh.inf";

                    longitudCadena = raw.length();

                    char *salidaRaw = new char[ longitudCadena + 1 ];
                    char *salidaInf = new char[ longitudCadena + 1 ];

                    raw.copy( salidaRaw, longitudCadena, 0 );
                    salidaRaw[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    inf.copy( salidaInf, longitudCadena, 0 );
                    salidaInf[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe han generado los correspondientes archivos de salida: " << endl;
                    cout << "\n\t1: " << raw << endl;
                    cout << "\t2: " << inf << endl;

                    voltearImagen(imgFlip);
                    escribirImagen(salidaRaw, salidaInf, imgFlip);

                    delete [] salidaRaw;
                    delete [] salidaInf;

                  }break;

                  case 3: /* este es el case a modificar. Y pegas tu nueva funcion o lo que hayas anadido. 

                    ya todo esta perfect ... Borra est comment al final */
                  {
                    string raw(nombreArchivo), inf(nombreArchivo);
                    Imagen imgInterpolada(imagen);
                    
                    raw += "_db.raw";
                    inf += "_db.inf";

                    longitudCadena = raw.length();

                    char *salidaRaw = new char[ longitudCadena + 1 ];
                    char *salidaInf = new char[ longitudCadena + 1 ];

                    raw.copy( salidaRaw, longitudCadena, 0 );
                    salidaRaw[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    inf.copy( salidaInf, longitudCadena, 0 );
                    salidaInf[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe han generado los correspondientes archivos de salida: " << endl;
                    cout << "\n\t1: " << raw << endl;
                    cout << "\t2: " << inf << endl;

                    voltearImagen(imgInterpolada); // aqui va interpolada..
                    escribirImagen(salidaRaw, salidaInf, imgInterpolada);

                    delete [] salidaRaw;
                    delete [] salidaInf;

                  }break;

                  case 4:
                  {
                    string raw(nombreArchivo), inf(nombreArchivo);
                    Imagen img4N(imagen);
                    
                    raw += "_4n.raw";
                    inf += "_4n.inf";

                    longitudCadena = raw.length();

                    char *salidaRaw = new char[ longitudCadena + 1 ];
                    char *salidaInf = new char[ longitudCadena + 1 ];

                    raw.copy( salidaRaw, longitudCadena, 0 );
                    salidaRaw[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    inf.copy( salidaInf, longitudCadena, 0 );
                    salidaInf[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe han generado los correspondientes archivos de salida: " << endl;
                    cout << "\n\t1: " << raw << endl;
                    cout << "\t2: " << inf << endl;

                    nivelesGris(img4N);
                    escribirImagen(salidaRaw, salidaInf, img4N);

                    delete [] salidaRaw;
                    delete [] salidaInf;

                  }break;

                  case 5:
                  {
                    string raw(nombreArchivo), inf(nombreArchivo), txt(nombreArchivo);
                    Imagen imgEcu(imagen);
                    
                    raw += "_ecu.raw";
                    inf += "_ecu.inf";
                    txt += "_ecu.txt";

                    longitudCadena = raw.length();

                    char *salidaRaw = new char[ longitudCadena + 1 ];
                    char *salidaInf = new char[ longitudCadena + 1 ];
                    char *salidaTxt = new char[ longitudCadena + 1 ];

                    raw.copy( salidaRaw, longitudCadena, 0 );
                    salidaRaw[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    inf.copy( salidaInf, longitudCadena, 0 );
                    salidaInf[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..

                    txt.copy( salidaTxt, longitudCadena, 0 );
                    salidaTxt[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe han generado los correspondientes archivos de salida: " << endl;
                    cout << "\n\t1: " << raw << endl;
                    cout << "\t2: " << inf << endl;
                    cout << "\t3: " << txt << endl;

                    histograma(salidaTxt, imagen);
                    equalizarHistograma(imgEcu);
                    escribirImagen(salidaRaw, salidaInf, imgEcu);

                    delete [] salidaRaw;
                    delete [] salidaInf;

                  }break;

                  case 6:
                  {
                    string txt(nombreArchivo);
                    Imagen histogramaImg(imagen);
                    
                    txt += "_ht.txt";
                    
                    longitudCadena = txt.length();

                    char *salidaTxt = new char[ longitudCadena + 1 ];

                    txt.copy( salidaTxt, longitudCadena, 0 );
                    salidaTxt[longitudCadena] = '\0'; // Terminador NULL para fin de cadena..
                    
                    cout << "\nSe ha generado el correspondiente archivo de salida: " << endl;
                    cout << "\n\t1: " << txt << endl;

                    histograma(salidaTxt, histogramaImg);
                    
                    delete [] salidaTxt;

                  }break;

                  default :
                    if(op < 0 || op > 6) 
                        cout << "Opcion incorrecta!..." << endl;
                    else 
                        cout << "Finalizando!..." << endl;
                }

                cout << "\nPresione <Enter> para continuar!..."; getchar();
    
            }while(op != 0);

    /* Fin de Operaciones sobre la IMG */

    return 0;
}

int leerImagen(char raw[], Imagen& imagen)
{
    ifstream ifs_raw;

    unsigned char *datosImg;
    
    int N, M, pixel;   

    ifs_raw.open(raw, ios::in | ios::binary);

    if(!ifs_raw) 
    {
        cout << "No se puede abrir archivo raw: " << raw << endl;
        exit(1);
    }

    imagen.getInfoImagen(N, M);

    datosImg = (unsigned char *) new unsigned char [M*N]; // Array 2D para albergar los pixeles de la imagen.

    ifs_raw.read( reinterpret_cast<char *>(datosImg), (M*N)*sizeof(unsigned char));

    if (ifs_raw.fail()) 
    {
        cout << "No se pudieron leer los bytes raw" << endl;
        exit(1);
    }

    ifs_raw.close();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) 
        {
            pixel = (int)datosImg[i*M + j];
            imagen.setValPixel(i, j, pixel);     
        }
    }
       
    delete [] datosImg;
    
    return(1);
}

int escribirImagen(char raw[], char inf[], Imagen& imagen)
{
    int N, M, pixel;
    unsigned char *datosImg;
    
    ofstream ofs_out;

    imagen.getInfoImagen(N, M);

    datosImg = (unsigned char *) new unsigned char [M*N];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++) 
        {
            pixel = imagen.getValPixel(i, j);
            datosImg[i*M + j] = (unsigned char)pixel;
        }
    }

    ofs_out.open(raw, ios::out | ios::binary);

    if (!ofs_out) 
    {
        cout << "No se puede abrir archivo raw: " << raw << endl;
        exit(1);
    }

    ofs_out.write( reinterpret_cast<char *>(datosImg), (M*N)*sizeof(unsigned char));

    if (ofs_out.fail()) 
    {
        cout << "No se pudo salvar la imagen... " << endl;
        exit(0);
    }

    ofs_out.close();

    delete [] datosImg;

    /* Imagen .raw de salida ha sido generada. Procedemos con la creacion del .inf de salida */

    ofs_out.open(inf); // reuso la misma variable.

    if (!ofs_out) 
    {
        cout << "No se puede crear archivo de salida .inf" << endl;
        exit(1);
    }

    ofs_out << M << " " << N;
    
    ofs_out.close();

    return(1);
}

void negarImagen(Imagen& imagen)
{
    int N, M, valPixel;

    imagen.getInfoImagen(N, M);

    Imagen imagenTemp(N, M);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            valPixel = -(imagen.getValPixel(i, j)) + 255;
            imagenTemp.setValPixel(i, j, valPixel);
        }
    }
    
    imagen = imagenTemp;
}

void voltearImagen(Imagen& imagen)
{
    int N, M, valPixel;

    imagen.getInfoImagen(N, M);

    Imagen tempImagen(N, M);

    for(int i = 0; i < N; i++)
    {
        for(int j = M-1, k = 0; j >= 0; j--, k++)
        {
            valPixel = imagen.getValPixel(i, j);
            tempImagen.setValPixel(i, k, valPixel);
        }
    }
    
    imagen = tempImagen;
}

void histograma(char salidaTxt[], Imagen& imagen)
{
    int N, M;

    for (int i = 0; i < 256; i++)
    {
        valoresHistograma[i] = 0;
    }

    ofstream ofs_out;

    ofs_out.open(salidaTxt);

    if (!ofs_out) 
    {
        cout << "No se puede crear archivo de salida .txt.." << endl;
        exit(1);
    }

    imagen.getInfoImagen(N, M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        
           valoresHistograma[imagen.getValPixel(i, j)]++ ;
    }

    for (int i = 0; i < 256; i++)  // Escribir el archivo de salida.
    
        ofs_out << i <<  " = " << valoresHistograma[i] << endl;

    ofs_out.close();
}

void nivelesGris(Imagen& imagen)
{
    int N, M, valPixel;

    imagen.getInfoImagen(N, M);

    Imagen imagenTemp(N, M);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            valPixel = imagen.getValPixel(i, j);
            imagenTemp.setValPixel(i, j, valorGris(valPixel));
        }
    }
    
    imagen = imagenTemp;
}

int valorGris(int pixel)
{
    if( (pixel >= 0) && (pixel <= 42) )
        return 0;

    if( (pixel >= 43) && (pixel <= 130) )
        return 85;

    if( (pixel >= 131) && (pixel <= 215) )
        return 176;

    return 255;
}

void equalizarHistograma(Imagen &imagen)
{
    int N, M, nivelGrisPixel, pixelEqualizado;

    imagen.getInfoImagen(N, M);

    Imagen imagenTemp(N, M);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            nivelGrisPixel = imagen.getValPixel(i, j);
            pixelEqualizado = floor( equalizar(nivelGrisPixel, N*M) * 255 );
            
            imagenTemp.setValPixel(i, j, pixelEqualizado);
        }
    }

    imagen = imagenTemp;
}

double equalizar(int nivelGrisPixel, int totalPixeles)
{
    int sum = 0;
    
    for(int i = 0; i <= nivelGrisPixel; i++)

        sum += valoresHistograma[i];
    
    return (double)sum/(double)(totalPixeles);
}

int menu()
{
    int op = 0;

    system("clear");

    cout << "\n\nM E N U   P R I N C I P A L\n" << endl;

    cout << "[1] Negar Imagen" << endl;
    cout << "[2] Flip Imagen" << endl;
    cout << "[3] Imagen Interpolada" << endl;
    cout << "[4] 4 Niveles de Gris" << endl;
    cout << "[5] Imagen Ecualizada" << endl;
    cout << "[6] Histograma de Imagen" << endl;
    cout << "[0] Salir" << endl;
    cout << "\nIngrese el numero correspondiente a su opcion: ";

    cin >> op;

    return op;
}
