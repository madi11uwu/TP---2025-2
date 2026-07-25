#include "src/Funciones.hpp"

int main() {
    //Juegos.txt
    //15/03/2021   G4812   TheElderRunes    4.75
    int fechas_juegos[MAX_JUEGOS]{};
    char codigo_juegos_char[MAX_JUEGOS]{};
    int codigos_juegos_int[MAX_JUEGOS]{};
    double rating[MAX_JUEGOS]{};
    int n_juegos = 0;
    cargar_juegos("Datos/Juegos.txt",fechas_juegos, codigo_juegos_char, codigos_juegos_int,
                  rating,n_juegos);
    probar_juegos("Reportes/reporte_prueba_juegos.txt",fechas_juegos, codigo_juegos_char, codigos_juegos_int,
                  rating,n_juegos);
    //Logros.txt
    int codigos_logros[MAX_LOGROS]{};
    int duracionPromedio[MAX_LOGROS]{};
    int n_logros = 0;
    cargar_logros("Datos/Logros.txt",codigos_logros,duracionPromedio,n_logros);
    probar_logros("Reportes/reporte_prueba_logros.txt",codigos_logros,duracionPromedio,n_logros);

    //LogrosEnJuegos.txt
    char codigos_char_juegos_logros[MAS_LOGROSJUEGOS]{};
    int codigos_int_juegos_logros[MAS_LOGROSJUEGOS]{};
    int codigos_logros_juegos_logros[MAS_LOGROSJUEGOS]{};
    int cantidad_juegos_logros[MAX_LOGROS]{};
    int n_logros_juegos = 0;
    cargar_logros_juegos("Datos/LogrosEnJuegos.txt",codigos_char_juegos_logros,
                        codigos_int_juegos_logros,codigos_logros_juegos_logros,
                        cantidad_juegos_logros,n_logros_juegos,n_logros,codigos_logros);
    ordenar_arreglos_logros("Datos/Logros.txt",codigos_logros,duracionPromedio,n_logros);
    return 0;
}
