#include "src/Funciones.hpp"

int main() {
    //Logros.txt
    int codigo_logro[MAX_LOGROS]{};
    int tiempoPromedio[MAX_LOGROS]{};
    int n_logros=0;
    cargar_logros("Datos/Logros.txt",codigo_logro,tiempoPromedio,n_logros);
    probar_logros("Reportes/reporte_prueba_logros.txt",codigo_logro,tiempoPromedio,n_logros);
    //Juegos.txt
    int FechaLanzamiento[MAX_JUEGOS]{};
    char c_juego[MAX_JUEGOS]{};
    int int_juego[MAX_JUEGOS]{};
    double rating[MAX_JUEGOS]{};
    int n_juego=0;
    cargar_juegos("Datos/Juegos.txt",FechaLanzamiento,c_juego,int_juego,rating,n_juego);
    probar_juegos("Reportes/reporte_prueba_juegos.txt",FechaLanzamiento,c_juego,int_juego,rating,n_juego);
    ordenarLogros(codigo_logro,tiempoPromedio,n_logros);
    imprimir_reporte("Reportes/Reporte.txt",codigo_logro,tiempoPromedio,n_logros);
    return 0;
}