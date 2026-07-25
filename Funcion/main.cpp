#include "src/Funciones.hpp"

int main() {
    struct Nodo *lista;
    char *palabras[500]{};
    int nro_palabras=0;
    cargarPersonajes("Datos/twd_character_status.csv",lista);
    completarLista("Datos/twd_character_sentences.csv",lista);
    imprimirReporte("Reporte/TWD-Reporte.txt",lista);
    //Palabra por palabra
    procesarPalabras("Datos/twd_character_sentences.csv",palabras,nro_palabras);
    return 0;
}


