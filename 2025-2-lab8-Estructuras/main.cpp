#include "src/Funciones.hpp"
#include "src/Reproduccion.hpp"
#include "src/Categoria.hpp"

int main() {
    //Categorias.csv´+
    struct Categoria *arrCategorias{};
    int cantidadCategorias=0;
    cargarCategorias("Datos/Categorias.csv",arrCategorias,cantidadCategorias);
    probarCategoras("Reportes/ReportePruebaCategorias.txt",arrCategorias,cantidadCategorias);
    //Reproducciones.csv
    llenarCategorias("Datos/Reproducciones.csv",arrCategorias,cantidadCategorias);
    probarCategoras("Reportes/ReporteLlenoCategorias.txt",arrCategorias,cantidadCategorias);
    CalcularPromedios(arrCategorias,cantidadCategorias);
    ordenarCategorias(arrCategorias,cantidadCategorias);
    imprimir_reporte("Reportes/Reporte.txt",arrCategorias,cantidadCategorias);
    ordenarCanales(arrCategorias,cantidadCategorias);
    imprimir_reporte("Reportes/ReporteCanales.txt",arrCategorias,cantidadCategorias);
    return 0;
}
