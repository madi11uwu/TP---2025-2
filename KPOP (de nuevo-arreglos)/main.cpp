#include "src/Funciones.hpp"

int main() {
    double tarifa=0.85;
    //Artistas.txt
    int int_artista[MAX_ARTISTAS]{};
    double rating[MAX_ARTISTAS]{};
    int n_artistas = 0;
    cargar_artistas("Datos/Artistas.txt",int_artista,rating,n_artistas);
    probar_artistas("Reportes/reporte_prueba_artistas.txt",int_artista,rating,n_artistas);
    //Canciones.txt
    int codigo_canciones[MAX_CANCIONES]{};
    int duracion[MAX_CANCIONES]{};
    int n_canciones = 0;
    cargar_canciones("Datos/Canciones.txt",codigo_canciones,duracion,n_canciones);
    probar_canciones("Reportes/reporte_prueba_canciones.txt",codigo_canciones,duracion,n_canciones);
    //Procesar datos de reproducciones
    int reproduccionesArtista[MAX_ARTISTAS]{};
    int reproduccionesCanciones[MAX_CANCIONES]{};
    int fecha_registroCanciones[MAX_CANCIONES]{};
    int tiempoTotalReproduccionCancion[MAX_CANCIONES]{};
    double GananciaPorArtista[MAX_ARTISTAS]{};
    procesarDatosReproducciones("Datos/Reproducciones.txt",int_artista,codigo_canciones,reproduccionesArtista,
        reproduccionesCanciones,fecha_registroCanciones,duracion,tiempoTotalReproduccionCancion,GananciaPorArtista,n_artistas,
        n_canciones,tarifa);
    imprimir_reporte("Reportes/Reporte.txt",int_artista,rating,codigo_canciones,duracion,reproduccionesArtista,
                    reproduccionesCanciones,fecha_registroCanciones,tiempoTotalReproduccionCancion,GananciaPorArtista,
                    n_canciones,n_artistas,tarifa);
    return 0;
}