#include "src/Funciones.hpp"
#include "src/Fecha.hpp"
#include "src/EmpresasRegistradas.hpp"
#include "src/TablaDeInfracciones.hpp"

int main() {
    struct TablaDeInfracciones *arrTablaDeInfracciones{};
    struct EmpresasRegistradas *arrEmpresasRegistradas{};
    int n_tablaDeInfracciones=0;
    int n_empresasRegistradas=0;
    cargar_tablaDeInfracciones("Datos/TablaDeInfracciones_Lab08.csv",arrTablaDeInfracciones,n_tablaDeInfracciones);
    cargar_empresasRegistradas("Datos/EmpresasRegistradas_Lab08.csv",arrEmpresasRegistradas,n_empresasRegistradas);
    LlenarPlacasDeEmpresas("Datos/PlacasRegistradas_Lab08.txt", arrEmpresasRegistradas,
                                 n_empresasRegistradas);
    CompletarEmpresasRegistradas("Datos/InfraccionesCometidas_Lab08.csv", arrEmpresasRegistradas,
                                 arrTablaDeInfracciones,n_empresasRegistradas,n_tablaDeInfracciones);
    imprimirReportePorFin("Reportes/Reporte", arrTablaDeInfracciones, n_tablaDeInfracciones,
                          arrEmpresasRegistradas, n_empresasRegistradas);
    return 0;
}


