#include "src/Funciones.hpp"

int main() {
    int fechaInicial=20240101,fechaFinal=20241231;
    generarReporte(fechaInicial,fechaFinal,"Datos/Clientes.txt","Datos/Libros.txt",
                    "Datos/Ventas.txt","Reportes/Reporte.txt");
    return 0;
}