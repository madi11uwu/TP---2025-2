#include "src/Funciones.hpp"

int main() {
    generarReporteRepartos("Datos/RepartosARealizar.txt","Datos/PlatosOfrecidos.txt",
                            "Datos/Clientes.txt","Datos/Repartidores.txt",
                            "Reportes/Reporte.txt");
    return 0;
}