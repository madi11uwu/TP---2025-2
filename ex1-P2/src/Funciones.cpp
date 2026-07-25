//
// Created by Madi on 26/10/2025.
//

#include "Funciones.hpp"

void insertar_ordenado(int codigo, int duracion, int idioma, char c_categoria, int categoria_int, int * codigo_stream,
                      int * codigo_idioma, char * char_categoria, int * int_categoria, int n_streams) {
    int i=n_streams-1;
    while (i>=0 and codigo_idioma[i]<idioma) {
        codigo_idioma[i+1]=codigo_idioma[i];
        codigo_stream[i+1]=codigo_stream[i];
        char_categoria[i+1]=char_categoria[i];
        int_categoria[i+1]=int_categoria[i];
        i--;
    }
}

void cargar_ordenado_streams(const char *streams,int *codigo_stream, int *duracion_stream, int *codigo_idioma, char *char_categoria,
                             int *int_categoria, int n_streams) {
    ifstream leer_streams;
    apertura_lectura(streams,leer_streams);
    int codigo,idioma,categoria_int,duracion;
    char c_categoria;
    while (true) {
        leer_streams>>codigo;
        if (leer_streams.eof()) break;
        duracion=almacenar_duracion(leer_streams);
        leer_streams>>idioma>>c_categoria>>categoria_int;
        insertar_ordenado(codigo, duracion, idioma, c_categoria, categoria_int,
                          codigo_stream, codigo_idioma, char_categoria, int_categoria, n_streams);
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

int almacenar_duracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

int almacenar_fecha(ifstream &leer) {
    int yyyy,mm,dd;
    char c;
    leer>>yyyy>>c>>mm>>c>>dd;
    return (yyyy*10000+mm*100+dd);
}
