#include "src/Funciones.hpp"

int main() {
    int fecha_artistas[MAX_ARTISTAS]{};
    char codigo_char_artistas[MAX_ARTISTAS]{};
    int codigo_int_artistas[MAX_ARTISTAS]{};
    double rating[MAX_ARTISTAS]{};
    int n_artistas = 0;
    //Artistas.txt
    cargar_artistas("Data/Artistas.txt",fecha_artistas,codigo_char_artistas,codigo_int_artistas,
        rating,n_artistas);
    probar_artistas("Reporte/reporte_prueba_artistas.txt",fecha_artistas,codigo_char_artistas,codigo_int_artistas,
        rating,n_artistas);
    //Canciones.txt
    int codigos_canciones[MAX_CANCIONES]{};
    int duracion_canciones[MAX_CANCIONES]{};
    int n_canciones=0;
    //Reproducciones.txt
    int reproducciones_tiempo_total[MAX_ARTISTAS]{};
    double Revenue[MAX_ARTISTAS]{};
    int TotalReproducciones[MAX_CANCIONES]{};
    cargar_canciones("Data/Canciones.txt",codigos_canciones,duracion_canciones,n_canciones);
    probar_canciones("Reporte/reporte_prueba_canciones.txt",codigos_canciones,duracion_canciones,n_canciones);

    generar_reporte("Data/Reproducciones.txt",fecha_artistas,codigo_char_artistas,codigo_int_artistas,rating,
        codigos_canciones,duracion_canciones,reproducciones_tiempo_total,Revenue,TotalReproducciones);
    return 0;
}