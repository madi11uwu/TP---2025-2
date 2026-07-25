#include "src/Funciones.hpp"

int main() {
    //Streams.txt
    int codigo_stream[MAX_STREAMS]{};
    int duracion_stream[MAX_STREAMS]{};
    int codigo_idioma[MAX_STREAMS]{};
    char char_categoria[MAX_STREAMS]{};
    int int_categoria[MAX_STREAMS]{};
    int n_streams=0;
    cargar_ordenado_streams("Datos/Streams.txt",codigo_stream, duracion_stream, codigo_idioma,
                            char_categoria, int_categoria, n_streams);

    return 0;
}
