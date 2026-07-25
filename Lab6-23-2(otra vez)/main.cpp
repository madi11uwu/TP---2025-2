#include "src/Funciones.hpp"

int main() {
    //TablaDeInfracciones.txt
    int codigo_infraccion[MAX_INFRACCIONES]{};
    double multa[MAX_INFRACCIONES]{};
    int n_infraciones = 0;
    cargar_ordenado("Datos/TablaDeInfracciones_Lab06.txt",
                    codigo_infraccion, multa, n_infraciones);
    prueba_infracciones("Reportes/PruebaTablaInf.txt", codigo_infraccion,
                        multa, n_infraciones);
    //InfraccionesCometidas.txt
    int arrDNI[MAX_INFRACCIONES]{};
    int arrMasMultaAntigua[MAX_INFRACCIONES]{};
    int arrUltimaPendiente[MAX_INFRACCIONES]{};
    double arrTotalMultas[MAX_INFRACCIONES]{};
    double arrTotalPagadas[MAX_INFRACCIONES]{};
    double arrTotalPendientes[MAX_INFRACCIONES]{};

    return 0;
}
