//
// Created by Madi on 12/10/2025.
//

#include "Funciones.hpp"

void cargarClientes(const char *clientes, int *DNICliente, int *codigo_distrito, char *c_vehiculo, double *descuento,
    int &n_clientes) {
    ifstream leer_clientes;
    apertuta_lectura(clientes,leer_clientes);
    int DNI;
    char c;
    while (true) {
        leer_clientes >> DNI;
        if (leer_clientes.eof())break;
        DNICliente[n_clientes] = DNI;
        ignorar(leer_clientes,']');
        leer_clientes >> codigo_distrito[n_clientes];
        ignorar(leer_clientes,' ');
        leer_clientes >> ws>>c_vehiculo[n_clientes]>>ws;
        c=leer_clientes.get();
        if (c=='S') {
            leer_clientes>>descuento[n_clientes]>>c;
        }
        else descuento[n_clientes]=0.0;
        n_clientes++;
    }
}

void probarClientes(const char *reporte_clientes, int *DNICliente, int *codigo_distrito, char *c_vehiculo, double *descuento,
    int n_clientes) {
    ofstream write;
    apertura_escritura(reporte_clientes,write);
    int i=0;
    write<<"CLIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"DNI DEL CLIENTE";
    write<<setw(10)<<""<<"CODIGO DEL DISTRITO";
    write<<setw(10)<<""<<"TIPO DE VEHICULO";
    write<<setw(10)<<""<<"DESCUENTO"<<endl;
    while (i<n_clientes) {
        write<<DNICliente[i];
        write<<setw(10)<<""<<codigo_distrito[i];
        write<<setw(10)<<""<<c_vehiculo[i];
        write<<setw(10)<<""<<descuento[i]<<endl;
        i++;
    }
}

void apertuta_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
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
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"RELACION DE PLATOS VENDIDOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimirEncabezadoSecundario(ofstream &write) {
    write<<setw(ANCHO_REPORTE/3)<<""<<"CANTIDAD DE PLATOS";
    write<<setw(ANCHO_REPORTE/3)<<""<<"MONTOS RECAUDADOS"<<endl;
    write<<"CODIGO";
    write<<setw(ANCHO_REPORTE/12)<<""<<"PRECIO";
    write<<setw(ANCHO_REPORTE/12)<<""<<"PREPARADOS";
    write<<setw(ANCHO_REPORTE/12)<<""<<"ATENDIDOS";
    write<<setw(ANCHO_REPORTE/12)<<""<<"NO ATENDIDOS";
    write<<setw(ANCHO_REPORTE/12)<<""<<"DESCUENTO";
    write<<setw(ANCHO_REPORTE/12)<<""<<"ESPERADO";
    write<<setw(ANCHO_REPORTE/12)<<""<<"BRUTO";
    write<<setw(ANCHO_REPORTE/12)<<""<<"RECIBIDO"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimirReporte(const char*reporte,int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido) {
    ofstream write;
    apertura_escritura(reporte,write);
    int i=0;
    double TotalEsperado=0.0,totalBruto=0.0,totalRecibido=0.0;
    imprimirEncabezado(write);
    imprimirEncabezadoSecundario(write);
    while (i<n_platos) {
        write<<codigo_plato[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<precio_plato[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<cantidadHecha[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<cantidadAtentida[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<cantidadNoAtendida[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<descuento_plato[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<MontoEsperado[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<montoBruto[i];
        write<<setw(ANCHO_REPORTE/12)<<""<<montoRecibido[i]<<endl;
        TotalEsperado+=MontoEsperado[i];
        totalBruto+=montoBruto[i];
        totalRecibido+=montoRecibido[i];
        i++;
    }
    imprimir_Totales(write,TotalEsperado,totalBruto,totalRecibido);
}

void imprimir_Totales(ofstream &write,double TotalEsperado,double totalBruto,double totalRecibido) {
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(100)<<""<<"TOTALES: "<<TotalEsperado<<setw(2)<<"";
    write<<totalBruto<<setw(2)<<""<<totalRecibido<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void LimpiarArreglos(int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato, int n_platos,
    int *cantidadAtentida, int *cantidadNoAtendida, double *MontoEsperado, double *montoBruto, double *montoRecibido) {
    int i=0;
    while (i<n_platos) {
        //if ()
        i++;
    }
}

void ignorar(ifstream &leer, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargarPlatos(const char *platos, int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
    int &n_platos) {
    ifstream leer_platos;
    apertuta_lectura(platos,leer_platos);
    int codigo;
    char c;
    while (true) {
        leer_platos>>codigo;
        if (leer_platos.eof())break;
        codigo_plato[n_platos]=codigo;
        ignorar(leer_platos,'}');
        leer_platos>>precio_plato[n_platos];
        leer_platos>>cantidadHecha[n_platos];
        c=leer_platos.get();
        if (c!='\n') {
            leer_platos>>descuento_plato[n_platos]>>c;
        }
        else descuento_plato[n_platos]=0.0;
        n_platos++;
    }
}

void probarPlatos(const char *reporte_platos, int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
    int n_platos) {
    ofstream write;
    apertura_escritura(reporte_platos, write);
    int i=0;
    write<<"PLATOS OFRECIDOS"<<endl;
    imprimir_linea(ANCHO_REPORTE, ',', write);
    write<<"CODIGO DEL PLATO";
    write<<setw(10)<<""<<"PRECIO";
    write<<setw(10)<<""<<"CANTIDAD HECHA";
    write<<setw(10)<<""<<"DESCUENTO"<<endl;
    while (i<n_platos) {
        write<<codigo_plato[i];
        write<<setw(10)<<""<<precio_plato[i];
        write<<setw(10)<<""<<cantidadHecha[i];
        write<<setw(10)<<""<<descuento_plato[i]<<endl;
        i++;
    }
}

void GenerarArreglos(const char *repartos, int *DNICliente,double *descuento,
                    int n_clientes, int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido) {
    ifstream leer_repartos;
    apertuta_lectura(repartos, leer_repartos);
    int pedido,DNILeido,cantidad,codigoPlato,pos_cliente,pos_plato;
    char c;
    while (true) {
        leer_repartos>>pedido;
        if (leer_repartos.eof()) break;
        leer_repartos>>DNILeido;
        pos_cliente=Buscar(DNICliente,n_clientes,DNILeido);
        while (true) {
            leer_repartos>>cantidad>>codigoPlato;
            pos_plato=Buscar(codigo_plato,n_platos,codigoPlato);
            if (pos_plato!=-1) {
                cantidadAtentida[pos_plato]++;
                cantidadNoAtendida[pos_plato]=cantidadHecha[pos_plato]-cantidadAtentida[pos_plato];
                MontoEsperado[pos_plato]=precio_plato[pos_plato]*cantidadHecha[pos_plato];
                montoBruto[pos_plato]+=precio_plato[pos_plato];
                montoRecibido[pos_plato]+=precio_plato[pos_plato]*((100-descuento_plato[pos_plato])/100.0)-precio_plato[pos_plato]*descuento[pos_cliente]/100.0;
            }
            else cout<<"No se encontró este plato"<<endl;
            c=leer_repartos.get();
            if (c=='\n') break;
        }
    }
}

int Buscar(int *DNICliente,int n_clientes,int DNILeido) {
    int i=0;
    while (i<n_clientes) {
        if (DNICliente[i]==DNILeido) return i;
        i++;
    }
    return -1;
}

void ordenarArreglos(int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido) {
    for (int i=0;i<n_platos-1;i++)
        for (int k=i+1;k<n_platos;k++) {
            if (cantidadHecha[i]<cantidadHecha[k]) {
                swapInt(cantidadHecha[i],cantidadHecha[k]);
                swapInt(codigo_plato[i],codigo_plato[k]);
                swapDouble(precio_plato[i],precio_plato[k]);
                swapDouble(descuento_plato[i],descuento_plato[k]);
                swapDouble(montoBruto[i],montoBruto[k]);
                swapDouble(montoRecibido[i],montoRecibido[k]);
                swapDouble(MontoEsperado[i],MontoEsperado[k]);
                swapInt(cantidadAtentida[i],cantidadAtentida[k]);
                swapInt(cantidadNoAtendida[i],cantidadNoAtendida[k]);
            }
        }
}

void swapInt(int &a,int &b) {
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void swapDouble(double &a,double &b) {
    double aux;
    aux=a;
    a=b;
    b=aux;
}

