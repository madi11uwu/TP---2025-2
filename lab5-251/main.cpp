#include "src/Funciones.hpp"

int main() {
    char c_infraccion[MAX_TABLAINFRACCIONES]{};
    int int_infraccion[MAX_TABLAINFRACCIONES]{};
    double multas[MAX_TABLAINFRACCIONES]{};
    int n_infracciones = 0;
    cargarInfracciones("Datos/Tabla de infracciones.txt",c_infraccion,int_infraccion,multas,n_infracciones);
    probarInfracciones("Reportes/reporte_prueba_infracciones.txt",c_infraccion,int_infraccion,multas,n_infracciones);
    //Empresas Registradas.txt
    int DNIRepre[MAX_EMPRESAS]{};
    int n_empresas = 0;
    cargarEmpresas("Datos/Empresas registradas.txt",DNIRepre,n_empresas);
    probarEmpresas("Reportes/reporte_prueba_empresas.txt",DNIRepre,n_empresas);
    return 0;
}