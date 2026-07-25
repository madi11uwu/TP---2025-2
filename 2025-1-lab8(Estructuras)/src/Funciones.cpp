//
// Created by Madi on 9/11/2025.
//

#include "Funciones.hpp"
#include "Fecha.hpp"
#include "EmpresasRegistradas.hpp"
#include "TablaDeInfracciones.hpp"
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

void cargar_tablaDeInfracciones(const char *file, TablaDeInfracciones *&tabla_de_infracciones,
                                int &n_tabla_de_infracciones) {
    ifstream read;
    apertura_lectura(file, read);
    char *codigo;
    tabla_de_infracciones=new struct TablaDeInfracciones[MAX_TABLA];
    while (true) {
        codigo=leer_cadena(read,MAX_CARACTERES,',');
        if (read.eof())break;
        tabla_de_infracciones[n_tabla_de_infracciones].codigo=asignar_cadena(codigo);
        tabla_de_infracciones[n_tabla_de_infracciones].multa=leer_double(read);
        tabla_de_infracciones[n_tabla_de_infracciones].descripcion=leer_cadena(read,MAX_CARACTERES,'\n');
        n_tabla_de_infracciones++;
    }
}

void cargar_empresasRegistradas(const char *file, struct EmpresasRegistradas *&empresas_registradas,
                                int &n_empresas_registradas) {
    ifstream read;
    apertura_lectura(file, read);
    int DNI;
    char *cadena,*cadena1;
    empresas_registradas = new struct EmpresasRegistradas[MAX_EMPRESAS]();
    while (true) {
        read>>DNI;
        if (read.eof())break;
        read.get();
        empresas_registradas[n_empresas_registradas].dni=DNI;
        cadena=leer_cadena(read,MAX_CARACTERES,',');
        cadena=modificarCadena(cadena);
        empresas_registradas[n_empresas_registradas].nombre=asignar_cadena(cadena);
        empresas_registradas[n_empresas_registradas].distrito=leer_cadena(read,MAX_CARACTERES,'\n');
        n_empresas_registradas++;
    }
}

char * leer_cadena(ifstream &read, int n, char delim) {
    char buffer[n];
    char *str;
    read.getline(buffer, n, delim);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);
    return str;
}

char * asignar_cadena(const char *nombre) {
    char *str;
    str = new char[strlen(nombre)+1];
    strcpy(str, nombre);
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

char * modificarCadena(char *cadena) {
    char *str;
    str = new char[strlen(cadena)+1];
    strcpy(str, cadena);
    for (int i = 0; str[i]; i++) {
        if (str[i]>='a' and str[i]<='z' and str[i]!=' ')str[i]-=32;
    }
    return str;
}

void LlenarPlacasDeEmpresas(const char *file, struct EmpresasRegistradas *empresas_registradas,
                                  int n_empresas_registradas) {
    ifstream read;
    apertura_lectura(file, read);
    int DNI,pos;
    char *placa;
    while (true) {
        read>>DNI;
        if (read.eof()) break;
        placa=leer_cadena_exacta(read);
        pos=BuscarEmpresa(n_empresas_registradas,empresas_registradas,DNI);
        if (pos!=-1) {
            cout<<empresas_registradas[pos].numPlacas<<endl;
            empresas_registradas[pos].placas[empresas_registradas[pos].numPlacas]=asignar_cadena(placa);
            empresas_registradas[pos].numPlacas++;
        }
    }
}

int BuscarEmpresa(int n,EmpresasRegistradas *empresas_registradas,int DNI) {
    for (int i=0; i<n; i++) {
        if (empresas_registradas[i].dni==DNI) {
            return i;
        }
    }
    return -1;
}

int BuscarPlacaEnEmpresa(char * placa, struct EmpresasRegistradas * empresas_registradas, int n_empresas_registradas) {
    for (int i=0; i<n_empresas_registradas; i++) {
        for (int j=0; empresas_registradas[i].placas[j]; j++) {
            if (strcmp(empresas_registradas[i].placas[j],placa)==0) {
                return i;
            }
        }
    }
    return -1;
}

void ordenarEmpresas(struct EmpresasRegistradas *empresas, int n_empresas) {
    for (int i=0; i<n_empresas-1; i++) {
        for (int k=i+1; k<n_empresas; k++) {
            if (strcmp(empresas[i].distrito,empresas[k].distrito)>0 or
                (strcmp(empresas[i].distrito,empresas[k].distrito)==0 and
                empresas[i].fechaDeInfraccion.fecha<empresas[k].fechaDeInfraccion.fecha)) {
                swapStructEmpresa(empresas[i],empresas[k]);
            }
        }
    }
}

void swapStructEmpresa(struct EmpresasRegistradas &a, struct EmpresasRegistradas &b) {
    struct EmpresasRegistradas aux;
    aux=a;
    a=b;
    b=aux;
}

void swaprStructTabla(struct TablaDeInfracciones &a, struct TablaDeInfracciones &b) {
    struct TablaDeInfracciones aux;
    aux=a;
    a=b;
    b=aux;
}

void ordenarTabla(struct TablaDeInfracciones *tabla, int n_infracciones) {
    for (int i=0; i<n_infracciones-1; i++) {
        for (int k=0;k<n_infracciones;k++) {
            if (strcmp(tabla[i].codigo,tabla[k].codigo)<0)
                swaprStructTabla(tabla[i],tabla[k]);
        }
    }
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTES"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE INFRACCIONES POR EMPRESA"<<endl;
    imprimir_linea(ANCHO_REPORTE, '=', write);
    write<<setw(15)<<""<<"EMPRESA";
    write<<setw(20)<<""<<"FECHA INF.";
    write<<setw(5)<<""<<"FECHA PAGO";
    write<<setw(20)<<""<<"CANTIDAD"<<endl;
    write<<"No. DNI";
    write<<setw(5)<<""<<"NOMBRE";
    write<<setw(5)<<""<<"DISTRITO";
    write<<setw(5)<<""<<"PLACAS";
    write<<setw(10)<<""<<"MAS ANTIGUA";
    write<<setw(2)<<""<<"MAS RECIENTE";
    write<<setw(2)<<""<<"TOTAL PAGADO";
    write<<setw(2)<<""<<"TOTAL DEUDA";
    write<<setw(3)<<""<<"DE FALTAS"<<endl;
    imprimir_linea(ANCHO_REPORTE, '=', write);
}

void imprimirReportePorFin(const char *file, TablaDeInfracciones *tabla,
                           int n_infracciones, EmpresasRegistradas *empresas_registradas,
                           int n_empresas) {
    // write<<setw(5)<<""<<"NOMBRE";
    // write<<setw(5)<<""<<"DISTRITO";
    // write<<setw(5)<<""<<"PLACAS";
    // write<<setw(10)<<""<<"MAS ANTIGUA";
    // write<<setw(2)<<""<<"MAS RECIENTE";
    // write<<setw(2)<<""<<"TOTAL PAGADO";
    // write<<setw(2)<<""<<"TOTAL DEUDA";
    // write<<setw(3)<<""<<"DE FALTAS"<<endl;
    ofstream write;
    apertura_escritura(file,write);
    imprimir_encabezado(write);
    int nroCliente=1;
    for (int i=0; i<n_empresas; i++) {
        write<<nroCliente<<")";
        write<<setw(2)<<""<<empresas_registradas[i].dni;
        write<<setw(2)<<""<<empresas_registradas[i].nombre;
        write<<setw(2)<<""<<empresas_registradas[i].distrito;
        write<<setw(2)<<"";
        for (int k=0;empresas_registradas[i].placas[k];k++) {
            write<<empresas_registradas[i].placas[k]<<"/";
        }
        write<<setw(2)<<"";
        imprimir_fecha(write,empresas_registradas[i].fechaDeInfraccion.fecha);
        write<<setw(2)<<"";
        imprimir_fecha(write,empresas_registradas[i].fechaDePago.fecha);
        write<<setw(2)<<""<<empresas_registradas[i].totalPagado;
        write<<setw(2)<<""<<empresas_registradas[i].totalAdeudado;
        write<<setw(2)<<""<<empresas_registradas[i].cantidadDeFaltas<<endl;
        nroCliente++;
    }
    imprimir_linea(ANCHO_REPORTE, '=', write);
}

void imprimir_fecha(ofstream &write, int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(4)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

char * leer_cadena_exacta(ifstream &read) {
    char buffer[MAX_CARACTERES],*str;
    read>>buffer;
    if (read.eof()) return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

void CompletarEmpresasRegistradas(const char *file, struct EmpresasRegistradas *empresas_registradas,
                                  struct TablaDeInfracciones *tabla,int n_empresas_registradas,
                                  int n_tablaDeInfracciones) {
    ifstream read;
    apertura_lectura(file, read);
    int aa,dd,mm,fecha,posInfraccion,posEmpresa,ddP,aaP,mmP,fechaP;
    char c,*placa,*codigoInfraccion,pago;
    while (true) {
        read>>dd;
        if (read.eof()) break;
        read>>c>>mm>>c>>aa,read.get();
        fecha=almacenarFecha(dd,mm,aa);
        placa=leer_cadena(read,MAX_CARACTERES,',');
        codigoInfraccion=leer_cadena(read,MAX_CARACTERES,',');
        read>>pago,read.get();
        posInfraccion=BuscarInfraccion(codigoInfraccion,tabla,n_tablaDeInfracciones);
        posEmpresa=BuscarPlacaEnEmpresa(placa,empresas_registradas,n_empresas_registradas);
        if (pago=='N') ddP=0,mmP=0,aaP=0,fechaP=almacenarFecha(ddP,mmP,aaP);
        else read>>ddP>>c>>mmP>>c>>aaP;
        if (posEmpresa!=-1) {
            if (empresas_registradas[posEmpresa].fechaDeInfraccion.fecha==0 or
                fecha<empresas_registradas[posEmpresa].fechaDeInfraccion.fecha) {
                empresas_registradas[posEmpresa].fechaDeInfraccion.aa=aa;
                empresas_registradas[posEmpresa].fechaDeInfraccion.mm=mm;
                empresas_registradas[posEmpresa].fechaDeInfraccion.dd=dd;
                empresas_registradas[posEmpresa].fechaDeInfraccion.fecha=fecha;
            }
            if (empresas_registradas[posEmpresa].fechaDePago.fecha==0 or
                fechaP>empresas_registradas[posEmpresa].fechaDePago.fecha) {
                empresas_registradas[posEmpresa].fechaDePago.aa=aaP;
                empresas_registradas[posEmpresa].fechaDePago.mm=mmP;
                empresas_registradas[posEmpresa].fechaDePago.dd=ddP;
                empresas_registradas[posEmpresa].fechaDePago.fecha=fechaP;
            }
            empresas_registradas[posEmpresa].cantidadDeFaltas++;
            if (posInfraccion!=-1) {
                empresas_registradas[posEmpresa].totalDeMultas+=tabla[posInfraccion].multa;
                if (pago=='N') empresas_registradas[posEmpresa].totalAdeudado+=tabla[posInfraccion].multa;
                else empresas_registradas[posEmpresa].totalPagado+=tabla[posInfraccion].multa;
            }
        }
    }
}

int BuscarInfraccion(char *codInfraccion,struct TablaDeInfracciones *tabla,int n) {
    for (int i=0; i<n; i++) {
        if (strcmp(tabla[i].codigo,codInfraccion)==0) {
            return i;
        }
    }
    return -1;
}

int almacenarFecha(int dd,int mm,int aa) {
    return aa*10000+mm*100+dd;
}


