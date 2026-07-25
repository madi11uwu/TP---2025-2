#include "src/Funciones.hpp"
#include "src/Canal.hpp"
#include "src/Categoria.hpp"
#include "src/Nodo.hpp"

int main() {
    struct Nodo *lista;
    llenarLista("Datos/Categorias.csv",lista,'O');
    llenarCanales("Datos/StreamsReproducidos.csv",lista);
    EliminarPorDescripcion(lista);
    imprimirReporte("Reportes/Reporte.txt",lista);
    return 0;
}

