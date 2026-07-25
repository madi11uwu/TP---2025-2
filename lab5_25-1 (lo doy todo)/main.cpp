#include "src/Funciones.hpp"

int main() {
    //EmpresasRegistradas.txt
    int DNI[MAX_EMPRESAS]{};
    int n_empresas = 0;
    cargar_Empresas("Datos/EmpresasRegistradas.txt",DNI,n_empresas);
    probar_empresas("Reportes/reporte_prueba_empresas.txt",DNI,n_empresas);
    //TablaDeInfracciones.txt
    char c_infraccion[MAX_TABLAINFRACCIONES]{};
    int int_infraccion[MAX_TABLAINFRACCIONES]{};
    double multas[MAX_TABLAINFRACCIONES]{};
    int n_tablaInfracciones = 0;
    cargar_TablaInfracciones("Datos/TablaDeInfracciones.txt",c_infraccion,int_infraccion,multas,
                            n_tablaInfracciones);
    probar_TablaInfracciones("Reportes/reporte_prueba_infracciones.txt",c_infraccion,
                            int_infraccion,multas,n_tablaInfracciones);
    return 0;
}