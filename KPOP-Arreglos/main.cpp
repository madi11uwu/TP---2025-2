#include "src/Funciones.hpp"

int main() {
    //Artistas.txt
    int fechaDebut[MAX_ARTISTAS]{};
    int int_codigo[MAX_ARTISTAS]{};
    double rating[MAX_ARTISTAS]{};
    int n_artistas=0;
    cargarArtistas("Datos/Artistas.txt",fechaDebut,int_codigo,rating,n_artistas);
    probarArtistas("Reportes/reporte_artistas.txt",fechaDebut,int_codigo,rating,n_artistas);
    //Canciones.txt
    int c_cancion[MAX_CANCIONES]{};
    int duracion[MAX_CANCIONES]{};
    int n_canciones=0;
    cargarCanciones("Datos/Canciones.txt",c_cancion,duracion,n_canciones);
    probarCanciones("Reportes/reporte_prueba_canciones.txt",c_cancion,duracion,n_canciones);

    //Armar Arreglos con Reproducciones.txt
    double tarifa=0.85,GananciaArtista[MAX_ARTISTAS]{};
    int FechaCanciones[MAX_CANCIONES]{},ReproduccionesCancion[MAX_CANCIONES]{},ReproduccionesArtista[MAX_ARTISTAS]{};
    int DuracionTotal[MAX_CANCIONES]{};
    armarArreglos("Datos/Reproducciones.txt",c_cancion,duracion,n_canciones,fechaDebut,int_codigo,rating,n_artistas,tarifa,
                    FechaCanciones,ReproduccionesCancion,ReproduccionesArtista,
                    GananciaArtista,DuracionTotal);
    imprimir_reporte("Reportes/Reporte.txt",c_cancion,duracion,n_canciones,
                    fechaDebut,int_codigo,rating,n_artistas,tarifa,
                    FechaCanciones,ReproduccionesCancion,ReproduccionesArtista,
                    GananciaArtista,DuracionTotal);
    cout<<"Hola"<<endl;
    return 0;
}