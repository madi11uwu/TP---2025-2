#include "src/Funciones.hpp"

int main() {
    //Reproducciones.txt
    int arrFechaRepro[MAX_REPRODUCCIONES]{};
    char *arrNombreCanal[MAX_REPRODUCCIONES]{};
    char *arrCodigoCategoria[MAX_REPRODUCCIONES]{};
    double arrRating[MAX_REPRODUCCIONES]{};
    double arrTasa[MAX_REPRODUCCIONES]{};
    int arrDuracion[MAX_REPRODUCCIONES]{};
    int n_reproducciones = 0;
    cargar_reproducciones("Datos/Reproducciones.txt", arrFechaRepro,
                          arrNombreCanal, arrCodigoCategoria, arrRating, arrTasa,
                          arrDuracion, n_reproducciones);
    probar_reproducciones("Reportes/ReporteDePruebaDeReproducciones.txt", arrFechaRepro,
                          arrNombreCanal, arrCodigoCategoria, arrRating, arrTasa,
                          arrDuracion, n_reproducciones);
    //Categorias.txt
    char *arrCodCategoria[MAX_CATEGORIA]{};
    char *arrnombreCategoria[MAX_CATEGORIA]{};
    int n_categoria = 0;
    cargar_categorias("Datos/Categorias.txt", arrCodCategoria,
                      arrnombreCategoria, n_categoria);
    probar_categorias("Reportes/ReporteDePruebaDeCategorias.txt",
                      arrCodCategoria, arrnombreCategoria,
                      n_categoria);
    imprimir_reportes(arrCodCategoria, arrnombreCategoria, arrFechaRepro,
                      arrCodigoCategoria, arrNombreCanal, arrRating, arrTasa,
                      arrDuracion, n_categoria, n_reproducciones);
    return 0;
}
