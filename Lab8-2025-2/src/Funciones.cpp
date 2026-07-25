//
// Created by Madi on 1/12/2025.
//

#include "Funciones.hpp"

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

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}

int almacenarDuracion(ifstream &read) {
    int hh,mm,ss;
    char c;
    read>>hh>>c>>mm>>c>>ss;
    return hh*3600+mm*60+ss;
}

void imprimirDuracion(int duracion, ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void insertar_ordenado(struct Categoria *&categoria, char *cod_categoria,
                       int &cantidad_categorias,char *nombre,char *descripcion,
                       struct Reproduccion *reproduccion) {
    int i=cantidad_categorias-1;
    while (i>=0 and strcmp(categoria[i].nombre,nombre)>0) {
        categoria[i+1]=categoria[i];
        i--;
    }
    categoria[i+1].nombre=nombre;
    categoria[i+1].descripcion=descripcion;
    categoria[i+1].codigo=cod_categoria;
    categoria[i+1].reproducciones=reproduccion;
    cantidad_categorias++;
}

void CargarCategorias(const char *str, struct Categoria *&categoria, int &cantidad_categorias) {
    ifstream read;
    apertura_lectura(str,read);
    categoria=new Categoria[MAX_CATEGORIAS]{};
    char *codCategoria;
    char *nombre,*descripcion;
    while (true) {
        codCategoria=leer_cadena(10,',',read);
        if (read.eof())break;
        nombre=leer_cadena(40,',',read);
        descripcion=leer_cadena(120,'\n',read);
        Reproduccion *r=new Reproduccion[15]{};
        // categoria[cantidad_categorias].codigo=codCategoria;
        // categoria[cantidad_categorias].nombre=leer_cadena(40,',',read);
        // categoria[cantidad_categorias].descripcion=leer_cadena(120,'\n',read);
        // categoria[cantidad_categorias].reproducciones=new Reproduccion[15]{};
        // cantidad_categorias++;
        insertar_ordenado(categoria, codCategoria,
                           cantidad_categorias,nombre,
                           descripcion,r);
    }
}

void probarCategorias(const char *str, struct Categoria *categoria, int cantidad_categorias) {
    ofstream write;
    apertura_escritura(str,write);
    write<<setw((120-strlen("REPORTE POR CATEGORIAS"))/2)<<"";
    write<<"REPORTE POR CATEGORIAS:"<<endl;
    imprimirLinea(120,'=',write);
    for (int i = 0; i < cantidad_categorias; i++) {
        write<<"Codigo: "<<categoria[i].codigo<<endl;
        write<<"Nombre: "<<categoria[i].nombre<<endl;
        write<<"Descripcion: "<<categoria[i].descripcion<<endl;
        imprimirLinea(120,'-',write);
        write<<"REPRODUCCIONES: "<<endl;
        for (int j = 0; j < categoria[i].numReproducciones; j++) {
            write<<"CANAL: "<<categoria[i].reproducciones[j].canal;
            write<<setw(5)<<""<<"RATING: "<<categoria[i].reproducciones[j].rating;
            write<<setw(5)<<""<<"DURACION: ";
            imprimirDuracion(categoria[i].reproducciones[j].duracion, write);
            write<<endl;
            write<<setw(5)<<""<<"COMENTARIOS: "<<endl;
            for (int k=0;k<categoria[i].reproducciones[j].numComentarios;k++) {
                write<<setw(5)<<""<<"- ";
                write<<categoria[i].reproducciones[j].comentarios[k]<<endl;
            }
        }
        imprimirLinea(120,'=',write);
    }
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

int BuscarCategoria(char * cod_categoria, int cantidad_categorias, struct Categoria * categoria) {
    for (int i = 0; i < cantidad_categorias; i++) {
        if (strcmp(categoria[i].codigo, cod_categoria) == 0) return i;
    }
    return -1;
}

void llenarReproducciones(const char * str, struct Categoria * categoria, int cantidad_categorias) {
    ifstream read;
    apertura_lectura(str,read);
    char *Canal,*codCategoria;
    double rating;
    int duracion,posCategoria;
    while (true) {
        Canal=leer_cadena(30,',',read);
        if (read.eof())break;
        codCategoria=leer_cadena(10,',',read);
        rating=leer_double(read);
        duracion=almacenarDuracion(read);
        read.get();
        posCategoria=BuscarCategoria(codCategoria,cantidad_categorias,categoria);
        if (posCategoria!=-1) {
            int n=categoria[posCategoria].numReproducciones;
            categoria[posCategoria].reproducciones[n].rating=rating;
            categoria[posCategoria].reproducciones[n].duracion=duracion;
            categoria[posCategoria].reproducciones[n].canal=Canal;
            categoria[posCategoria].numReproducciones++;
        }
    }
}

void ordenarArreglo(struct Categoria *categoria,int n) {
    for (int i=0;i<n-1;i++) {
        for (int k=i+1;k<n;k++) {
            if (strcmp(categoria[i].nombre,categoria[k].nombre) > 0) {
                swapStructCategoria(categoria[i],categoria[k]);
            }
        }
    }
}

void swapStructCategoria(struct Categoria &a, struct Categoria &b) {
    struct Categoria aux;
    aux=a;
    a=b;
    b=aux;
}

void llenarComentarios(const char *str, struct Categoria *categoria, int cantidad_categorias) {
    ifstream read;
    apertura_lectura(str,read);
    char *canal,*comentario;
    while (true) {
        canal=leer_cadena(30,',',read);
        if (read.eof())break;
        comentario=leer_cadena(100,'\n',read);
        for (int i=0;i<cantidad_categorias;i++) {
            for (int j=0;j<categoria[i].numReproducciones;j++) {
                if (strcmp(canal,categoria[i].reproducciones[j].canal)==0) {
                    int n=categoria[i].reproducciones[j].numComentarios;
                    categoria[i].reproducciones[j].comentarios[n]=comentario;
                    categoria[i].reproducciones[j].numComentarios++;
                }
            }
        }
    }
}

