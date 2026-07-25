#include "src/Funciones.hpp"


int main() {
    //TablaDeInfracciones.txt
    int arrCodigoInfraccion[MAX_INFRACCIONES]{};
    double arrMultasInfraccion[MAX_INFRACCIONES]{};
    int n_tablaInfraccion=0;
    cargar_ordenado_infraccion("Datos/TablaDeInfracciones_Lab06.txt",
                               arrCodigoInfraccion, arrMultasInfraccion, n_tablaInfraccion);
    probar_ordenado_infraccion("Reportes/Reporte_prueba", arrCodigoInfraccion,
                               arrMultasInfraccion, n_tablaInfraccion);
    //InfraccionesCometidas.txt
    int arrDNI[MAX_INFRACCIONES]{};
    int arrMasMultaAntigua[MAX_INFRACCIONES]{};
    int arrUltimaPendiente[MAX_INFRACCIONES]{};
    double arrTotalMultas[MAX_INFRACCIONES]{};
    double arrTotalPagadas[MAX_INFRACCIONES]{};
    double arrTotalPendientes[MAX_INFRACCIONES]{};
    llenarArreglos("Datos/InfraccionesCometidas_Lab06.txt", arrDNI,
                   arrMasMultaAntigua,arrMultasInfraccion, arrUltimaPendiente, arrTotalMultas,
                   arrTotalPagadas, arrCodigoInfraccion,arrTotalPendientes,n_tablaInfraccion);

    return 0;
}
