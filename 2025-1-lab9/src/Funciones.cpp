//
// Created by Madi on 16/11/2025.
//

#include "Funciones.hpp"
#include "Fecha.hpp"
#include "InfraccionCometida.hpp"
#include "EmpresasRegistradas.hpp"
#include "TablaDeInfracciones.hpp"
void apertura_lectura(const char *file, ifstream &read) {
    read.open(file,ios::in);
    if (!read.is_open()) {
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

char *leer_str(ifstream &read, int n, char c) {
    char *str;
    char buffer[n];
    read>>ws;
    read.getline(buffer,n,c);
    if (c!='\n')
        if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * asignar_str(const char *name) {
    char *str;
    str = new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

int leer_int(ifstream &read) {
    int n;
    read>>n;
    read.get();
    return n;
}

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

int almacenarFecha(ifstream &read) {
    int dd,mm,yyyy;
    char c;
    read>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void imprimirFecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(4)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

char * modificarTexto(char *cadena) {
    char *str;
    str = new char[strlen(cadena)+1];
    strcpy(str,cadena);
    for (int i = 0; str[i]; i++) {
        if (str[i]>='a' and str[i]<='z')str[i]-=32;
    }
    return str;
}

void llenarTabla(const char *file, struct TablaDeInfracciones *&tabla_de_infracciones, int &n_tabla) {
    ifstream read;
    apertura_lectura(file, read);
    char *codigo;
    char *descripcion;
    tabla_de_infracciones=new struct TablaDeInfracciones[MAX_TABLA];
    while (true) {
        codigo=leer_str(read,MAX_CARACTERES,',');
        if (read.eof())break;
        tabla_de_infracciones[n_tabla].codigo=asignar_str(codigo);
        tabla_de_infracciones[n_tabla].multa=leer_double(read);
        descripcion=leer_str(read,MAX_CARACTERES,'\n');
        descripcion=modificarTexto(descripcion);
        tabla_de_infracciones[n_tabla].descripcion=asignar_str(descripcion);
        n_tabla++;
    }
}

void cargarEmpresas(const char *file, struct EmpresasRegistradas *&empresas_registradas,
                    int &n_empresas_registradas) {
    ifstream read;
    apertura_lectura(file, read);
    empresas_registradas=new struct EmpresasRegistradas[MAX_EMPRESAS]();
    int dni;
    char *nombre;
    char *distrito;
    while (true) {
        read>>dni;
        if (read.eof()) break;
        read.get();
        empresas_registradas[n_empresas_registradas].dni=dni;
        nombre=leer_str(read,MAX_CARACTERES,',');
        nombre=modificarTexto(nombre);
        empresas_registradas[n_empresas_registradas].nombre=asignar_str(nombre);
        distrito=leer_str(read,MAX_CARACTERES,'\n');
        distrito=modificarTexto(distrito);
        empresas_registradas[n_empresas_registradas].distrito=asignar_str(distrito);
        empresas_registradas[n_empresas_registradas].infraccion=new struct InfraccionCometida[40];
        n_empresas_registradas++;
    }
}

void CompletarEmpresas(const char *str, struct EmpresasRegistradas *empresas_registradas,
                       int n_empresas_registradas) {
    ifstream read;
    apertura_lectura(str,read);
    int dni,pos;
    char *placa;
    while (true) {
        read>>dni;
        if (read.eof())break;
        read.get();
        placa=leer_str(read,MAX_CARACTERES,'\n');
        pos=BuscarEmpresa(dni,empresas_registradas,n_empresas_registradas);
        if (pos!=-1) {
            empresas_registradas[pos].placas[empresas_registradas[pos].numPlacas]=asignar_str(placa);
            empresas_registradas[pos].numPlacas++;
        }
    }
}

int BuscarEmpresa(int dni, struct EmpresasRegistradas *empresa, int n_empresas) {
    for (int i = 0; i < n_empresas; i++) {
        if (empresa[i].dni==dni) {
            return i;
        }
    }
    return -1;
}

int BuscarInfraccion(char * infraccion, struct TablaDeInfracciones * tabla_de_infracciones, int n_tabla) {
    for (int i = 0; i < n_tabla; i++) {
        if (strcmp(infraccion,tabla_de_infracciones[i].codigo)==0) {
            return i;
        }
    }
    return -1;
}

void completarEmpresas(const char *str, struct EmpresasRegistradas *empresas_registradas,
                       struct TablaDeInfracciones *tabla_de_infracciones,
                       int n_empresas_registradas, int n_tabla) {
    ifstream read;
    apertura_lectura(str,read);
    int dd,mm,aa,ddP,mmP,aaP,pos,posInfraccion,fecha,fechaPago;
    char c,*placa,*infraccion;
    bool pago;
    while (true) {
        read>>dd;
        if (read.eof())break;
        read>>c>>mm>>c>>aa>>c;
        fecha=almacenarFecha(dd,mm,aa);
        placa=leer_str(read,MAX_CARACTERES,',');
        infraccion=leer_str(read,MAX_CARACTERES,',');
        read>>c;
        if (c=='P') {
            pago=true;
            read.get();
            read>>ddP>>c>>mmP>>c>>aaP;
        }
        else {
            pago=false;
            ddP=0,mmP=0,aaP=0;
        }
        fechaPago=almacenarFecha(ddP,mmP,aaP);
        pos=BuscarEmpresa2(placa,empresas_registradas,n_empresas_registradas);
        posInfraccion=BuscarInfraccion(infraccion,tabla_de_infracciones,n_tabla);
        llenarArreglos(pos, posInfraccion, empresas_registradas,
                       tabla_de_infracciones, pago,
                       placa, infraccion, fechaPago, fecha);
    }
}

void llenarArreglos(int pos, int posInfraccion, struct EmpresasRegistradas *empresas_registradas,
                    struct TablaDeInfracciones *tabla_de_infracciones,
                    bool pago, char *placa, char *infraccion, int fechaPago, int fecha) {

    if (pos != -1) {
        if (posInfraccion != -1) {
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].multaPagada = pago;
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].placa =
                    asignar_str(placa);
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].codigoDeLaInfraccion
                    = asignar_str(infraccion);
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].multa =
                    tabla_de_infracciones[posInfraccion].multa;
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].descripcion =
                    asignar_str(tabla_de_infracciones[posInfraccion].descripcion);
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].fechaDePago.fecha =
                    fechaPago;
            empresas_registradas[pos].infraccion[empresas_registradas[pos].cantidadDeInfracciones].fechaDeInfraccion.
                    fecha = fecha;
            empresas_registradas[pos].cantidadDeInfracciones++;
            if (pago) {
                empresas_registradas[pos].totalPagado = tabla_de_infracciones[posInfraccion].multa;
            } else
                empresas_registradas[pos].totalAdeudado = tabla_de_infracciones[posInfraccion].multa;
        }
    }
}

void ordenarEmpresas(struct EmpresasRegistradas *empresas, int n) {
    for (int i = 0; i < n-1; i++)
        for (int k=i+1; k<n; k++) {
            if (strcmp(empresas[i].distrito, empresas[k].distrito) > 0) {
                swapStructEmpresas(empresas[i],empresas[k]);
            }
        }
    for (int j=0; j<n; j++) {
        for (int i = 0; i <empresas[j].cantidadDeInfracciones-1; i++) {
            for (int k=i+1; k<empresas[j].cantidadDeInfracciones; k++) {
                if (empresas[j].infraccion[i].multaPagada==false and empresas[j].infraccion[k].multaPagada==true) {
                    swapStructInfraccion(empresas[j].infraccion[i],empresas[j].infraccion[k]);
                }
            }
        }
    }

}

void swapStructEmpresas(struct EmpresasRegistradas &a, struct EmpresasRegistradas &b) {
    struct EmpresasRegistradas aux;
    aux = a;
    a = b;
    b = aux;
}

void swapStructInfraccion(struct InfraccionCometida &a, struct InfraccionCometida &b) {
    struct InfraccionCometida aux;
    aux = a;
    a = b;
    b = aux;
}

void imprimirSegundaParte(ofstream &write, struct InfraccionCometida *infraccion,int cantidadDeInfracciones,int &n) {
    double totalPagado=0.0, totalAdeudado=0.0;
    int nroMulta=1;
    for (int i = 0; i < cantidadDeInfracciones; i++)
        if (infraccion[i].multaPagada) {
            write<<n<<")";
            write<<setw(3)<<"";
            imprimirFecha(infraccion[i].fechaDeInfraccion.fecha,write);
            write<<setw(3)<<""<<infraccion[i].placa;
            write<<setw(3)<<""<<infraccion[i].codigoDeLaInfraccion;
            write<<setw(10)<<""<<infraccion[i].descripcion;
            write<<setw(3)<<""<<infraccion[i].multa;
            write<<setw(8)<<"";
            imprimirFecha(infraccion[i].fechaDePago.fecha,write);
            write<<endl;
            totalPagado+=infraccion[i].multa;
            n++;
        }
    imprimirTotales(totalPagado,write,'P');
    imprimirSegundoEncabezado(write,'S');
    for (int i = 0; i < cantidadDeInfracciones; i++)
        if (!infraccion[i].multaPagada) {
            write<<nroMulta<<")";
            write<<setw(3)<<"";
            imprimirFecha(infraccion[i].fechaDeInfraccion.fecha,write);
            write<<setw(3)<<""<<infraccion[i].placa;
            write<<setw(3)<<""<<infraccion[i].codigoDeLaInfraccion;
            write<<setw(10)<<""<<infraccion[i].descripcion;
            write<<setw(3)<<""<<infraccion[i].multa;
            write<<endl;
            totalAdeudado+=infraccion[i].multa;
            nroMulta++;
        }
    imprimirTotales(totalAdeudado,write,'A');
}

void imprimirTotales(double total,ofstream &write,char c) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    if (c=='P') {
        write<<"TOTAL PAGADO: "<<total<<endl;
    }
    else {
        write<<"TOTAL ADEUDADO: "<<total<<endl;
    }
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_reporte(const char *file,struct EmpresasRegistradas *empresas_registradas,
                      struct TablaDeInfracciones *tabla_de_infracciones,
                      int n_empresas_registradas, int n_tabla) {
    ofstream write;
    apertura_escritura(file,write);
    imprimir_encabezado(write);
    int nro_empresa=1;
    for (int i = 0; i < n_empresas_registradas; i++) {
        imprimirPrimeraParte(write, empresas_registradas[i].dni,
                             empresas_registradas[i].nombre, empresas_registradas[i].distrito,
                             empresas_registradas[i].placas, nro_empresa);
        imprimirSegundoEncabezado(write,'P');
        nro_empresa++;
        int nroMulta=1;
        imprimirSegundaParte(write, empresas_registradas[i].infraccion,
                             empresas_registradas[i].cantidadDeInfracciones, nroMulta);
    }
}

void imprimirSegundoEncabezado(ofstream &write,char c) {
    if (c=='P') {
        write<<"MULTAS PAGADAS: "<<endl;
        write<<setw(5)<<""<<"FECHA";
        write<<setw(ANCHO_REPORTE/8)<<""<<"PLACAS";
        write<<setw(ANCHO_REPORTE/8)<<""<<"CODIGO DE INFRACCION";
        write<<setw(ANCHO_REPORTE/8)<<""<<"DESCRIPCION";
        write<<setw(ANCHO_REPORTE/8)<<""<<"MULTA";
        write<<setw(ANCHO_REPORTE/8)<<""<<"FECHA DE PAGO"<<endl;
    }
    else {
        write<<"MULTAS ADEUDADAS: "<<endl;
        write<<setw(5)<<""<<"FECHA";
        write<<setw(ANCHO_REPORTE/8)<<""<<"PLACAS";
        write<<setw(ANCHO_REPORTE/8)<<""<<"CODIGO DE INFRACCION";
        write<<setw(ANCHO_REPORTE/8)<<""<<"DESCRIPCION";
        write<<setw(ANCHO_REPORTE/8)<<""<<"MULTA"<<endl;
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
void imprimirPrimeraParte(ofstream &write, int dni, char *nombre,
                          char *distrito, char **placas,int i) {
    write<<setw(2)<<setfill('0')<<i<<")";
    write<<setfill(' ');
    write<<setw(3)<<""<<"DNI: "<<dni;
    write<<setw(5)<<""<<"NOMBRE: "<<nombre;
    write<<setw(5)<<""<<"DISTRITO: "<<distrito;
    write<<setw(5)<<""<<"PLACAS: ";
    for (int k=0;placas[k];k++) {
        write<<placas[k]<<"/";
    }
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTES"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE INFRACCIONES POR EMPRESA"<<endl;
    imprimir_linea(ANCHO_REPORTE, '=', write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

int almacenarFecha(int dd, int mm, int aa) {
    return (aa*10000+mm*100+dd);
}

int BuscarEmpresa2(char *placa, struct EmpresasRegistradas *empresas_registradas,
                    int n_empresas_registradas) {
    for (int i=0;i<n_empresas_registradas;i++) {
        for (int k=0;k<empresas_registradas[i].numPlacas;k++) {
            if (strcmp(empresas_registradas[i].placas[k],placa)==0) {
                return i;
            }
        }
    }
    return -1;
}