#include "src/Funciones.hpp"

int main() {
    //Libros.txt
    int codigo_libro[MAX_LIBROS]{};
    double precio_libro[MAX_LIBROS]{};
    int n_libros = 0;
    cargarLibros("Datos/Libros.txt",codigo_libro,precio_libro,n_libros);
    probarLibros("Reportes/reporte_prueba_libros.txt",codigo_libro,precio_libro,n_libros);
    ordenarArreglos(codigo_libro,precio_libro,n_libros);
    //Ventas.txt
    int unidadesVendidos[MAX_LIBROS]{};
    double promCalificacion[MAX_LIBROS]{};
    double TotalVentas[MAX_LIBROS]{};
    int FechaPrimeraVenta[MAX_LIBROS]{};
    int DNIPrimeraVenta[MAX_LIBROS]{};
    int FechaUltimaVenta[MAX_LIBROS]{};
    int DNIUltimaVenta[MAX_LIBROS]{};
    generarArreglos("Datos/Ventas.txt",promCalificacion,unidadesVendidos,
                    TotalVentas,FechaPrimeraVenta,DNIPrimeraVenta,
                    FechaUltimaVenta,DNIUltimaVenta,n_libros,codigo_libro,
                    precio_libro);
    imprimir_reporte("Reportes/Reporte.txt",codigo_libro,precio_libro,n_libros,
                      promCalificacion,unidadesVendidos,
                      TotalVentas,FechaPrimeraVenta,DNIPrimeraVenta,
                      FechaUltimaVenta,DNIUltimaVenta);
    return 0;
}