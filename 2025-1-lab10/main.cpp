#include "src/BibliotecasListas/Nodo.hpp"
#include "src/BibliotecasListas/Cuenta.hpp"
#include "src/BibliotecasListas/Lista.hpp"

int main() {
    struct Nodo *lista;
    struct Nodo *listaInicio;
    struct Nodo *listaFinal;
    llenarOrdenado("Datos/CuentasBancarias.csv",lista);
    llenarInicio("Datos/CuentasBancarias.csv",listaInicio);
    llenarFinal("Datos/CuentasBancarias.csv",listaFinal);
    CompletarDatos("Datos/MovimientosDeCuentas.csv",lista);
    CompletarDatos("Datos/MovimientosDeCuentas.csv",listaInicio);
    CompletarDatos("Datos/MovimientosDeCuentas.csv",listaFinal);
    imprimirReporte("Reportes/ReporteDeSaldosDeLasCuentas.txt",
                    lista);
    imprimirReporte("Reportes/ReporteDeSaldosDeLasCuentasInicio.txt",
                    listaInicio);
    imprimirReporte("Reportes/ReporteDeSaldosDeLasCuentasFinal.txt",
                    listaFinal);
    EliminarElementos(lista);
    imprimirReporte("Reportes/ReporteDeSaldosDeLasCuentasEliminado.txt",
                    lista);
    return 0;
}
