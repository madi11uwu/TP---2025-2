//
// Created by Madi on 3/11/2025.
//

#include "Funciones.hpp"

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
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

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"No."<<setw(5)<<""<<"PLATO OFRECIDO";
    write<<setw(20)<<""<<"CANTIDAD VENDIDA";
    write<<setw(10)<<""<<"PRECIO";
    write<<setw(10)<<""<<"INGRESO BRUTO";
    write<<setw(10)<<""<<"DESCUENTO";
    write<<setw(10)<<""<<"TOTAL"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void insertar_ordenado(int *arr_codigo_platos,
                       int *arr_num_platos_vendidos,
                       int &n_platos, int codigo_plato,
                       int cantidad) {
    int i=n_platos-1;
    while (i>=0 and arr_codigo_platos[i]>codigo_plato) {
        arr_codigo_platos[i+1]=arr_codigo_platos[i];
        arr_num_platos_vendidos[i+1]=arr_num_platos_vendidos[i];
        i--;
    }
    arr_codigo_platos[i+1]=codigo_plato;
    arr_num_platos_vendidos[i+1]=cantidad;
    n_platos++;
}

void llenarArreglos(const char *ofrecidos, double *arrPrecio,
                    double *arrIngresoBruto, double *arrDescuento,
                    bool *arrTieneDescuento, double *arrTotal,
                    char **descripcion,char **categoria,
                    int *arrCodigoPlatos,int *arrNumPlatosVendidos,
                    int n_platos) {
    ifstream leer_ofrecidos;
    apertura_lectura(ofrecidos,leer_ofrecidos);
    int pos,codigo;
    double precio,descuento;
    char *desc,*cate,c;
    bool tiene;
    while (true) {
        leer_ofrecidos >> codigo;
        if (leer_ofrecidos.eof()) break;
        desc = lectura_cadena_exacta(leer_ofrecidos);
        leer_ofrecidos >> precio;
        cate = lectura_cadena_exacta(leer_ofrecidos);
        c = leer_ofrecidos.get();
        if (c == '\n') {
            descuento = 0;
            tiene = false;
        } else {
            leer_ofrecidos >> descuento >> c;
            tiene = true;
        }
        pos = BuscarBinaria(arrCodigoPlatos, n_platos, codigo);
        if (pos != -1) {
            arrPrecio[pos] = precio;
            arrIngresoBruto[pos] = precio * arrNumPlatosVendidos[pos];
            arrTieneDescuento[pos] = tiene;
            arrDescuento[pos] = descuento;
            arrTotal[pos] = arrIngresoBruto[pos] * (100 - descuento) / 100.0;
            descripcion[pos] = desc;
            categoria[pos] = cate;
        }
    }
}

char *lectura_cadena_exacta(ifstream &leer) {
    char *str, buffer[MAX_CARACTERES];
    leer >> buffer;
    if (leer.eof()) return nullptr;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

char *ModificarCadena(char *cadena1, char *cadena2,
                      bool descuento) {
    bool InicioPalabra = true;
    for (int i = 0; cadena1[i]; i++) {
        if (cadena1[i] == '_') {
            cadena1[i] = ' ';
        }
        if (!InicioPalabra) {
            if (cadena1[i] >= 'A' and cadena1[i] <= 'Z') cadena1[i] += 32;
            if (cadena1[i]==' ')InicioPalabra = true;
        }
        else InicioPalabra = false;
    }
    char *nombre = new char[strlen(cadena1) + strlen(cadena2) + 2 + MAX_CARACTERES];
    if (descuento) {
        nombre = strcpy(nombre, cadena1);
        nombre = strcat(nombre, "-");
        nombre = strcat(nombre, "PROMOCIONADO");
        nombre = strcat(nombre, "-");
        nombre = strcat(nombre, cadena2);
    } else {
        nombre = strcpy(nombre, cadena1);
        nombre = strcat(nombre, "-");
        nombre = strcat(nombre, cadena2);
    }
    return nombre;
}

void imprimir_reporte(const char *reporte, double *arrPrecio,
                      double *arr_ingreso_bruto, double *arr_descuento,
                      bool *arr_tiene_descuento, double *arr_total,
                      char **descripcion, char **categoria, int *arr_codigo_platos,
                      int *arr_num_platos_vendidos, int n_platos) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimir_encabezado(write);
    int numPlato=1;
    for (int i = 0; i < n_platos; i++) {
        write<<"No."<<setw(3)<<setfill('0')<<numPlato<<")";
        write<<setfill(' ');
        write<<setw(4)<<arr_codigo_platos[i]<<setw(3)<<"";
        char *nombre=new char[MAX_CARACTERES+strlen(descripcion[i])+strlen(categoria[i])+2];
        nombre=ModificarCadena(descripcion[i],categoria[i],arr_tiene_descuento[i]);
        write<<nombre;
        write<<setw(20)<<""<<arr_num_platos_vendidos[i];
        write<<setw(10)<<""<<arrPrecio[i];
        write<<setw(10)<<""<<arr_ingreso_bruto[i];
        if (arr_tiene_descuento[i]) write<<setw(10)<<""<<arr_descuento[i]<<"%";
        else write<<setw(15)<<""<<"-";
        write<<setw(10)<<""<<arr_total[i]<<endl;
        numPlato++;
    }
}

void cargar_ordenado_repartos(const char *repartos, int *arrCodigoPlatos,
                              int *arrNumPlatosVendidos,
                              int &n_platos) {
    ifstream leer_repartos;
    apertura_lectura(repartos,leer_repartos);
    int numPedido,DNI,cantidad,codigo_plato,pos;
    char c;
    while (true) {
        leer_repartos>>numPedido;
        if (leer_repartos.eof()) break;
        leer_repartos>>DNI;
        while (true) {
            leer_repartos>>cantidad>>codigo_plato;
            pos=BuscarBinaria(arrCodigoPlatos,n_platos,codigo_plato);
            if (pos!=-1) {
                arrNumPlatosVendidos[pos]+=cantidad;
            }
            else {
                insertar_ordenado(arrCodigoPlatos,
                                  arrNumPlatosVendidos, n_platos,
                                  codigo_plato, cantidad);
            }
            c=leer_repartos.get();
            if (c=='\n')break;
        }
    }
}

int BuscarBinaria(int *arreglo,int n,int buscar) {
    int limite_inferior=0,limite_superior=n-1;
    int punto_medio;
    while (true) {
        if (limite_inferior>limite_superior) return -1;
        punto_medio=(limite_inferior+limite_superior)/2;
        if (arreglo[punto_medio]==buscar) return punto_medio;
        if (arreglo[punto_medio]<buscar) limite_inferior=punto_medio+1;
        else limite_superior=punto_medio-1;
    }
}

