#include "src/Funciones.hpp"

int main() {
    //PlatosOfrecidos.txt
    int codigo_platos[MAX_PLATOS]{};
    double precio_platos[MAX_PLATOS]{};
    int n_platos = 0;
    cargarPlatosOfrecidos("Datos/PlatosOfrecidos.txt",codigo_platos,precio_platos,n_platos);
    probarPlatosOfrecidos("Reporte/reporte_prueba_platos.txt",codigo_platos,precio_platos,n_platos);
    //Repartidores.txt
    int DNI_repartidores[MAX_REPARTIDORES]{};
    int codigo_distrito[MAX_REPARTIDORES]{};
    int n_distrito = 0;
    cargarRepartidores("Datos/Repartidores.txt",DNI_repartidores,codigo_distrito,n_distrito);
    probarRepartidores("Reporte/reporte_prueba_repartidor.txt",DNI_repartidores,codigo_distrito,n_distrito);
    return 0;
}