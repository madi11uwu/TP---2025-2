#include "srcLista/Lista.hpp"
#include "srcLista/ListaTAD.hpp"

int main() {
    struct Nodo *lista;
    //trabajaremos con una lista simplemente ligada
    crear_lista(lista, "Data/datos.txt");
    struct Lista lista_tad;
    crear_lista_TAD();
    return 0;
}
