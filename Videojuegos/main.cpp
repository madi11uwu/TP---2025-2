#include "src/Funciones.hpp"

int main() {
    //Juegos.txt
    int FechaCreacion[MAX_JUEGOS]{};
    char c_juego[MAX_JUEGOS]{};
    int int_juego[MAX_JUEGOS]{};
    double rating[MAX_JUEGOS]{};
    int n_juego = 0;
    cargarJuegos("Datos/Juegos.txt",FechaCreacion,c_juego,int_juego,
                rating,n_juego);
    probarJuegos("Reportes/reporte_prueba_juegos.txt",FechaCreacion,c_juego,int_juego,
                rating,n_juego);
    //Logros.txt
    int codigo_logro[MAX_LOGROS]{};
    int tiempo_promedio[MAX_LOGROS]{};
    int n_logro = 0;
    cargarLogros("Datos/Logros.txt",codigo_logro,tiempo_promedio,n_logro);
    probarLogros("Reportes/reporte_prueba_logros.txt",codigo_logro,
                tiempo_promedio,n_logro);
    //LogrosEnJuegos.txt
    char char_juego[MAX_LOGROSENJUEGOS]{};
    int num_juego[MAX_LOGROSENJUEGOS]{};
    int c_logros[MAX_LOGROSENJUEGOS]{};
    int n_logrosEnJuegos=0;
    cargarLogrosEnJuegos("Datos/LogrosEnJuegos.txt",char_juego,num_juego,
                            c_logros,n_logrosEnJuegos);
    probarLogrosEnJuegos("Reportes/reporte_prueba_logrosEnJuegos.txt",
                        char_juego,num_juego,c_logros,n_logrosEnJuegos);
    return 0;
}