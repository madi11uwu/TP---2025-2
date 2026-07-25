#include "src/Funciones.hpp"

int main() {
    GenerarReporte("Datos/EmpresasRegistradas.txt","Datos/InfraccionesCometidas.txt",
                    "Datos/PlacasRegistradas.txt","Datos/TablaDeInfracciones.txt",
                    "Reportes/Reporte.txt");
    return 0;
}