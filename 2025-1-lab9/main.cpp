#include "src/Funciones.hpp"
#include "src/Fecha.hpp"
#include "src/InfraccionCometida.hpp"
#include "src/EmpresasRegistradas.hpp"
#include "src/TablaDeInfracciones.hpp"

int main() {
    //TablaDeInfracciones.csv
    struct TablaDeInfracciones *tablaDeInfracciones{};
    struct EmpresasRegistradas *empresasRegistradas{};
    int n_empresasRegistradas=0;
    int n_tabla=0;
    llenarTabla("Datos/TablaDeInfracciones.csv",
                tablaDeInfracciones, n_tabla);
    cargarEmpresas("Datos/EmpresasRegistradas_Lab09.csv",
                   empresasRegistradas, n_empresasRegistradas);
    CompletarEmpresas("Datos/PlacasRegistradas_Lab09.csv",
                      empresasRegistradas, n_empresasRegistradas);
    completarEmpresas("Datos/InfraccionesCometidas_Lab09.csv",
                      empresasRegistradas, tablaDeInfracciones, n_empresasRegistradas,
                      n_tabla);
    ordenarEmpresas(empresasRegistradas,n_empresasRegistradas);
    imprimir_reporte("Reportes/Reporte.txt",empresasRegistradas, tablaDeInfracciones,
                     n_empresasRegistradas, n_tabla);

    return 0;
}
