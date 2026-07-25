#include "src/Funciones.hpp"

int main() {
    //Artistas.txt
    int fecha_artista[MAX_ARTISTAS]{};
    int codigo_int_artista[MAX_ARTISTAS]{};
    double rating_artista[MAX_ARTISTAS]{};
    int n_artistas = 0;
    cargar_artistas(fecha_artista,codigo_int_artista,rating_artista,n_artistas,"Data/Artistas.txt");
    probar_artistas(fecha_artista,codigo_int_artista,rating_artista,n_artistas,"Reporte/reporte_prueba_artistas.txt");
    //Canciones.txt
    int codigo_cancion[MAX_CANCIONES]{};
    int duracion_cancion[MAX_CANCIONES]{};
    int n_canciones = 0;
    cargar_canciones(codigo_cancion,duracion_cancion,n_canciones,"Data/Canciones.txt");
    probar_canciones(codigo_cancion,duracion_cancion,n_canciones,"Reporte/reporte_canciones.txt");
    //Reproducciones.txt
    int fecha_registro[MAX_CANCIONES]{};
    int reproducciones[MAX_CANCIONES]{};
    int reproduccionesTotalesTiempo[MAX_ARTISTAS]{};
    double gananciasRepro[MAX_ARTISTAS]{};
    int ReproDuracionCancion[MAX_CANCIONES]{};
    ordenarInformacion(fecha_registro,reproducciones,reproduccionesTotalesTiempo,gananciasRepro,codigo_cancion,codigo_int_artista,
        n_canciones,n_artistas,ReproDuracionCancion);
    imprimir_reporte();
    return 0;
}