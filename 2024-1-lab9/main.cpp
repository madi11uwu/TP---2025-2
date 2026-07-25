#include "src/Funciones.hpp"
#include "src/Cliente.hpp"
#include "src/Fecha.hpp"
#include "src/Venta.hpp"
#include "src/Libro.hpp"

int main() {
    struct Cliente *arrClientes{};
    struct Libro *arrLibros{};
    int n_clientes = 0;
    int n_libros = 0;
    cargarCliente("Datos/Clientes_laboratorio9.csv",
                  arrClientes, n_clientes);
    cargarLibros("Datos/Libros_laboratorio9.csv",
                 arrLibros, n_libros);
    completarLibros("Datos/Ventas_laboratorio9.csv",
                    arrLibros, n_libros);
    calcularRanking(arrLibros,n_libros);
    ordenarLibros(arrLibros,n_libros);
    imprimir_reporte("Reportes/Reporte.txt",arrLibros,n_libros,arrClientes,n_clientes);
    return 0;
}
