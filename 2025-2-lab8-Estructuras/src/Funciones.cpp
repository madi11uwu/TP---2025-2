//
// Created by Madi on 17/11/2025.
//

#include "Funciones.hpp"
#include "Reproduccion.hpp"
#include "Categoria.hpp"

void apertura_lectura(const char *file, ifstream &read) {
    read.open(file, ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/2)<<""<<"REPORTE POR CATEGORIAS"<<endl;
}

void cargarCategorias(const char *str, struct Categoria *&categoria,
                      int &cantidad_categorias) {
    ifstream read;
    apertura_lectura(str, read);
    categoria=new struct Categoria[MAX_CATEGORIAS]();
    char *codigo;
    char *nombre;
    while (true) {
        codigo=leer_str(MAX_CARACTERES,',',read);
        if (read.eof())break;
        categoria[cantidad_categorias].codigo=codigo;
        nombre=leer_str(MAX_CARACTERES,'\n',read);
        nombre=modificarCadena(nombre);
        categoria[cantidad_categorias].nombre=asignar_str(nombre);
        categoria[cantidad_categorias].reproducciones=new struct Reproduccion[15]();
        cantidad_categorias++;
    }
}

char * leer_str(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer, n,c);
    if (read.eof()) return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);
    return str;
}

int leer_int(ifstream &read) {
    int n;
    read>>n;
    read.get();
    return n;
}

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}

char * asignar_str(const char *name) {
    char *str;
    str = new char[strlen(name)+1];
    strcpy(str, name);
    return str;
}

void llenarCategorias(const char * str, struct Categoria * categoria, int cantidad_categorias) {
    ifstream read;
    apertura_lectura(str, read);
    char *canal;
    char *codigoCategoria;
    double rating;
    int duracion,pos;
    while (true) {
        canal=leer_str(MAX_CARACTERES,',',read);
        if (read.eof())break;
        codigoCategoria=leer_str(ANCHO_REPORTE,',',read);
        rating=leer_double(read);
        duracion=almacenarDuracion(read);
        pos=buscarCategoria(codigoCategoria,categoria,cantidad_categorias);
        if (pos!=-1) {
            categoria[pos].reproducciones[categoria[pos].numReproducciones].canal=asignar_str(canal);
            categoria[pos].reproducciones[categoria[pos].numReproducciones].duracion=duracion;
            categoria[pos].reproducciones[categoria[pos].numReproducciones].rating=rating;
            categoria[pos].duracionTotal+=duracion;
            categoria[pos].promedioRating+=rating;
            categoria[pos].numReproducciones++;
        }
    }
}

int buscarCategoria(char *codigo,struct Categoria *&categoria,int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(codigo,categoria[i].codigo)==0) {
            return i;
        }
    }
    return -1;
}

void ordenarCategorias(struct Categoria *categoria, int cantidad_categorias) {
    for (int i = 0; i < cantidad_categorias-1; i++) {
        for (int j = i+1; j < cantidad_categorias; j++) {
            if (categoria[i].numReproducciones>categoria[j].numReproducciones
                or (categoria[i].numReproducciones==categoria[j].numReproducciones
                    and categoria[i].promedioRating<categoria[j].promedioRating)) {
                swapStructCategorias(categoria[i],categoria[j]);
            }
        }
    }
}

void swapStructCategorias(struct Categoria &a, struct Categoria &b) {
    struct Categoria aux;
    aux=a;
    a=b;
    b=aux;
}

void CalcularPromedios(struct Categoria *categoria, int cantidad_categorias) {
    for (int i = 0; i < cantidad_categorias; i++) {
        categoria[i].promedioRating=categoria[i].promedioRating/categoria[i].numReproducciones;
    }
}

void imprimir_reporte(const char *str, struct Categoria *categoria,
                      int cantidad_categorias) {
    ofstream write;
    apertura_escritura(str,write);
    imprimir_encabezado(write);
    for (int i = 0; i < cantidad_categorias; i++) {
        write<<"Codigo: "<<categoria[i].codigo<<endl;
        write<<"Nombre: "<<categoria[i].nombre<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        write<<"REPRODUCCIONES:"<<endl;
        write<<"CANAL"<<setw(10)<<""<<"RATING"<<setw(10)<<""<<"DURACION"<<endl;
        for (int j = 0; j < categoria[i].numReproducciones; j++) {
            write<<categoria[i].reproducciones[j].canal;
            write<<setw(10)<<""<<categoria[i].reproducciones[j].rating;
            write<<setw(10)<<"";
            imprimir_duracion(categoria[i].reproducciones[j].duracion,write);
            write<<endl;
        }
        imprimir_linea(ANCHO_REPORTE,'-',write);
        write<<"RATING PROMEDIO: "<<categoria[i].promedioRating<<endl;
        write<<"DURACION TOTAL: ";
        imprimir_duracion(categoria[i].duracionTotal,write);
        write<<endl;
        imprimir_linea(ANCHO_REPORTE,'=',write);
    }
}

void ordenarCanales(struct Categoria *categoria, int cantidad_categorias) {
    for (int i = 0; i < cantidad_categorias; i++) {
        for (int j=0; j<categoria[i].numReproducciones-1; j++) {
            for (int k=j+1;k<categoria[i].numReproducciones;k++) {
                if (categoria[i].reproducciones[j].duracion<categoria[i].reproducciones[k].duracion) {
                    swapStructReproduccion(categoria[i].reproducciones[j],categoria[i].reproducciones[k]);
                }
            }
        }
    }
}

void swapStructReproduccion(struct Reproduccion &a, struct Reproduccion &b) {
    struct Reproduccion aux;
    aux=a;
    a=b;
    b=aux;
}

void probarCategoras(const char *str, struct Categoria *categoria,
                     int cantidad_categorias) {
    ofstream write;
    apertura_escritura(str,write);
    write<<"CATEGORIAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(5)<<""<<"CODIGO";
    write<<setw(5)<<""<<"NOMBRE";
    write<<setw(5)<<""<<"NUMERO DE REPRODUCCIONES";
    write<<setw(5)<<""<<"SUMA RATING";
    write<<setw(5)<<""<<"DURACION TOTAL"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    for (int i = 0; i < cantidad_categorias; i++) {
        write<<setw(5)<<""<<categoria[i].codigo;
        write<<setw(5)<<""<<categoria[i].nombre;
        write<<setw(5)<<""<<categoria[i].numReproducciones;
        write<<setw(5)<<""<<categoria[i].promedioRating;
        write<<setw(5)<<"";
        imprimir_duracion(categoria[i].duracionTotal,write);
        write<<endl;
        write<<setw(5)<<""<<"CANAL";
        write<<setw(5)<<""<<"RATING";
        write<<setw(5)<<""<<"DURACION"<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        for (int k=0;categoria[i].reproducciones[k].canal;k++) {
            write<<setw(5)<<""<<categoria[i].reproducciones[k].canal;
            write<<setw(5)<<""<<categoria[i].reproducciones[k].rating;
            write<<setw(5)<<"";
            imprimir_duracion(categoria[i].reproducciones[k].duracion,write);
            write<<endl;
        }
    }

}

void imprimir_duracion(int n, ofstream &write) {
    write<<setw(2)<<setfill('0')<<n/3600<<":";
    write<<setw(2)<<setfill('0')<<(n%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(n%3600)%60;
    write<<setfill(' ');
}

int almacenarDuracion(ifstream &read) {
    int dd,mm,aa;
    char c;
    read>>dd>>c>>mm>>c>>aa;
    return (dd*3600+mm*60+aa);
}

char * modificarCadena(char *name) {
    char *str;
    str = new char[strlen(name)+1];
    strcpy(str, name);
    bool inicioPalabra=true;
    for (int i = 0; str[i]; i++) {
        if (inicioPalabra) {
            if (str[i] >= 'a' and str[i] <= 'z') str[i] -= 32;
            inicioPalabra=false;
        }
        else {
            if (str[i]==' ') inicioPalabra=true;
        }
    }
    return str;
}


