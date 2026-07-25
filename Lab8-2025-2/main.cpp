#include "src/Funciones.hpp"

int main() {
    //Categorias.csv
    struct Categoria *arrCategorias;
    int cantidadCategorias=0;
    CargarCategorias("Datos/Categorias.csv",arrCategorias,cantidadCategorias);
    probarCategorias("Reportes/ReporteDePruebaDeCategorias.txt",arrCategorias,cantidadCategorias);
    //StreamsReproducidos.csv
    llenarReproducciones("Datos/StreamsReproducidos.csv",arrCategorias,cantidadCategorias);
    probarCategorias("Reportes/ReporteDePruebaConReproducciones.txt",arrCategorias,cantidadCategorias);
    ordenarArreglo(arrCategorias,cantidadCategorias);
    probarCategorias("Reportes/ReporteDePruebaOrdenado.txt",arrCategorias,cantidadCategorias);
    //ComentariosAlCanal.csv
    llenarComentarios("Datos/ComentariosAlCanal.csv",arrCategorias,cantidadCategorias);
    probarCategorias("Reportes/ReporteDePruebaConComentarios.txt",arrCategorias,cantidadCategorias);
    return 0;
}
