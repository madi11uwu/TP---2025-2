#include "src/Funciones.hpp"

int main() {
    //RepartosARealizar.txt
    int arrCodigoPlatos[MAX_PLATOS]{};
    int arrNumPlatosVendidos[MAX_PLATOS]{};
    int n_platos=0;
    cargar_ordenado_repartos("Datos/lab6_RepartosARealizar.txt",
                             arrCodigoPlatos, arrNumPlatosVendidos, n_platos);

    return 0;
}
