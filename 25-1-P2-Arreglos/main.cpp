#include "src/Funciones.hpp"

int main() {
    //TablaDeInfracciones.txt
    char c_infraccion[MAX_INFRACCIONES]{};
    int int_infraccion[MAX_INFRACCIONES]{};
    double multa[MAX_INFRACCIONES]{};
    int n_infraccion = 0;
    cargarInfracciones("Datos/TablaDeInfracciones.txt",c_infraccion,
                        int_infraccion,multa,n_infraccion);
    probarInfracciones("Reportes/reporte_prueba_tabla.txt",c_infraccion,
                        int_infraccion,multa,n_infraccion);
    //InfraccionesCometidas.txt

    return 0;
}