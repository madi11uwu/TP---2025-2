#include "src/Funciones.hpp"

int main() {
    int arrCodigoPlatos[MAX_NO_REPETIDOS]{};
    int arrNumPlatosVendidos[MAX_NO_REPETIDOS]{};
    int n_platos=0;
    cargar_ordenado_repartos("Datos/lab6_RepartosARealizar.txt", arrCodigoPlatos,
                             arrNumPlatosVendidos, n_platos);
    //PlatosOfrecidos.txt
    double arrPrecio[MAX_NO_REPETIDOS]{};
    double arrIngresoBruto[MAX_NO_REPETIDOS]{};
    double arrDescuento[MAX_NO_REPETIDOS]{};
    bool arrTieneDescuento[MAX_NO_REPETIDOS]{};
    double arrTotal[MAX_NO_REPETIDOS]{};
    char *descripcion[MAX_NO_REPETIDOS]{};
    char *categoria[MAX_NO_REPETIDOS]{};
    llenarArreglos("Datos/lab6_PlatosOfrecidos.txt", arrPrecio,
                   arrIngresoBruto, arrDescuento,
                   arrTieneDescuento, arrTotal,descripcion,categoria,
                   arrCodigoPlatos,arrNumPlatosVendidos, n_platos);
    imprimir_reporte("Reportes/Reporte.txt",arrPrecio,
                   arrIngresoBruto, arrDescuento,
                   arrTieneDescuento, arrTotal,descripcion,categoria,
                   arrCodigoPlatos,arrNumPlatosVendidos,n_platos);
    return 0;
}
