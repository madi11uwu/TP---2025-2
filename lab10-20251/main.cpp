#include "src/Funciones.hpp"
#include "src/Nodo.hpp"

int main() {
    struct Nodo *lista;
    crear_lista("Datos/CuentasBancarias.csv",lista);
    CompletarLista("Datos/MovimientosDeCuentas.csv",lista);
    imprimir_reporte("Reportes/ReporteDeSaldosDeLasCuentas.txt",lista);
    // EliminarCuentasPositivas(lista);
    // imprimir_reporte("Reportes/ReporteDeCuentasQueSeCierran.txt",lista);
    eliminarUnElemento(lista,90334731);
    imprimir_reporte("Reportes/ReporteDeSaldosDeLasCuentasEliminado.txt",lista);
    return 0;
}



