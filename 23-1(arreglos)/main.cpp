#include "src/Funciones.hpp"

int main() {
    //Libros.txt
    int codigo_libro[MAX_LIBROS]{};
    double precios[MAX_LIBROS]{};
    int n_libros = 0;
    cargarLibros("Datos/Libros.txt",codigo_libro,precios,n_libros);
    probarLibros("Reportes/reporte_prueba_libros.txt",codigo_libro,precios,n_libros);
    //Autores.txt
    int codigo_autor[MAX_AUTORES]{};
    int libros_autor[MAX_AUTORES]{};
    double porcentaje_regalias[MAX_AUTORES]{};
    int n_autores = 0;
    cargarAutores("Datos/Autores.txt",codigo_autor,libros_autor,porcentaje_regalias,n_autores);
    probarAutores("Reportes/reporte_prueba_autores.txt",codigo_autor,libros_autor,porcentaje_regalias,n_autores);
    //Trabajar con Ventas.
    int cantidadVentasLibros[MAX_LIBROS]{};
    double montoPorLibro[MAX_LIBROS]{};
    int fecha1=20230201,fecha2=20230315;
    GenerarArreglos ("Datos/Ventas.txt",codigo_libro,precios,n_libros,cantidadVentasLibros,
                    montoPorLibro,fecha1,fecha2);
    imprimir_reporte("Reportes/Reporte.txt",codigo_libro,precios,n_libros,cantidadVentasLibros,
                       montoPorLibro,codigo_autor,libros_autor,porcentaje_regalias,n_autores,fecha1,fecha2);
    return 0;
}