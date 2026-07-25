#include "src/Funciones.hpp"
#include "src/Vendedor.hpp"
#include "src/Nodo.hpp"


int main() {
    struct Nodo *lista;
    crear_lista_ordenada("Datos/Vendedores.csv",lista);
    completarLista("Datos/Ventas (1).txt",lista);
    imprimirReporte("Reportes/Reporte.txt",lista);
    EliminarInformacion(lista);
    imprimirReporte("Reportes/ReporteEliminado.txt",lista);
    return 0;
}
