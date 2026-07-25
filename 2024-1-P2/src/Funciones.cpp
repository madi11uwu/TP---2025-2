//
// Created by Madi on 12/10/2025.
//

#include "Funciones.hpp"

void cargarPacientes(const char *pacientes, int *DNIPacientes, int *codigo_distrito, int *anioNacimiento, double *descuento,
    int &n_pacientes) {
    ifstream leer_pacientes;
    apertura_lectura(pacientes,leer_pacientes);
    int DNI;
    while (true) {
        leer_pacientes>>DNI;
        if (leer_pacientes.eof()) break;
        DNIPacientes[n_pacientes]=DNI;
        ignorar(leer_pacientes,']');
        leer_pacientes>>codigo_distrito[n_pacientes];
        leer_pacientes>>anioNacimiento[n_pacientes];
        leer_pacientes>>descuento[n_pacientes];
        n_pacientes++;
    }
}

void probarPacientes(const char *reporte_pacientes, int *DNIPacientes, int *codigo_distrito, int *anioNacimiento, double *descuento,
    int n_pacientes) {
    ofstream write;
    apertura_escritura(reporte_pacientes,write);
    int i=0;
    write<<"PACIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"DNI DE PACIENTES";
    write<<setw(ANCHO_REPORTE/6)<<""<<"CODIGO DISTRITO";
    write<<setw(ANCHO_REPORTE/6)<<""<<"ANIO NACIMIENTO";
    write<<setw(ANCHO_REPORTE/6)<<""<<"DESCUENTO"<<endl;
    while(i<n_pacientes) {
        write<<DNIPacientes[i];
        write<<setw(ANCHO_REPORTE/6)<<""<<codigo_distrito[i];
        write<<setw(ANCHO_REPORTE/6)<<""<<anioNacimiento[i];
        write<<setw(ANCHO_REPORTE/6)<<""<<descuento[i]<<endl;
        i++;
    }
}

void cargarMedicinas(const char *medicinas, int *codigo_medicina, double *precio_medicina, int &n_medicina) {
    ifstream leer_medicinas;
    apertura_lectura(medicinas,leer_medicinas);
    int codigo;
    while (true) {
        leer_medicinas>>codigo;
        if (leer_medicinas.eof())break;
        ignorar(leer_medicinas,' ');
        leer_medicinas>>precio_medicina[n_medicina];
        codigo_medicina[n_medicina]=codigo;
        n_medicina++;
    }
}

void probarMedicinas(const char *reporte_medicina, int *codigo_medicina, double *precio_medicina, int n_medicina) {
    ofstream write;
    apertura_escritura(reporte_medicina,write);
    int i=0;
    write<<"MEDICINAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO DE MEDICINA";
    write<<setw(ANCHO_REPORTE/3)<<""<<"PRECIO"<<endl;
    while(i<n_medicina) {
        write<<codigo_medicina[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<precio_medicina[i]<<endl;
        i++;
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

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE SALUD S.A."<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"CONSOLIDADO DE ATENCION POR PACIENTE"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimirEncabezado1(ofstream &write) {
    write<<"CLASIFICACION";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"DISTRITO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"DNI PACIENTE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"%DESCUENTO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"CANT.CITAS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"CANT.MEDICINAS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"PAGO.MEDICINAS"<<endl;
}

void ignorar(ifstream &leer, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void GenerarArreglos(const char *citas, int *DNIPacientes, int *codigo_distrito,
                    int *anioNacimiento, double *descuento,
                    int n_pacientes, int *codigo_medicina,
                    double *precio_medicina, int n_medicina,
                    int *cantCitas,int *cantMedicinas,double *pagoMedicinas) {
    ifstream leer_citas;
    apertura_lectura(citas,leer_citas);
    int fecha,DNI,horaI,horaF,codigoMedico,pos_paciente,codigoMed,cantidad,pos_medicina;
    char c;
    while (true) {
        fecha=AlmacenarFecha(leer_citas);
        if (leer_citas.eof())break;
        leer_citas>>DNI;
        horaI=AlmacenarDuracion(leer_citas);
        horaF=AlmacenarDuracion(leer_citas);
        leer_citas>>codigoMedico;
        pos_paciente=BuscarPaciente(DNIPacientes,n_pacientes,DNI);
        if (pos_paciente!=-1) {
            cantCitas[pos_paciente]++;
        }
        else {
            cout<<"No se encontro al paciente"<<endl;
        }
        while (true) {
            c=leer_citas.get();
            if (c=='\n')break;
            leer_citas>>codigoMed>>cantidad;
            pos_medicina=BuscarPaciente(codigo_medicina,n_medicina,codigoMed);
            cantMedicinas[pos_paciente]++;
            pagoMedicinas[pos_paciente]+=precio_medicina[pos_medicina]*(100-descuento[pos_paciente]);
        }
    }
}

void ordenarArreglos(int *DNIPacientes, int *codigo_distrito, int *anioNacimiento,
                    double *descuento,int n_pacientes,int *cantCitas,int *cantMedicinas,
                    double *pagoMedicinas) {
    for (int i=0;i<n_pacientes-1;i++)
        for (int k=i+1;k<n_pacientes;k++) {
            if (anioNacimiento[i]<anioNacimiento[k] or (anioNacimiento[i]==anioNacimiento[k]
                and codigo_distrito[i]<codigo_distrito[k])) {
                swapInt(DNIPacientes[i],DNIPacientes[k]);
                swapInt(codigo_distrito[i],codigo_distrito[k]);
                swapInt(anioNacimiento[i],anioNacimiento[k]);
                swapDouble(descuento[i],descuento[k]);
                swapInt(cantCitas[i],cantCitas[k]);
                swapInt(cantMedicinas[i],cantMedicinas[k]);
                swapDouble(pagoMedicinas[i],pagoMedicinas[k]);
            }
        }
}

void imprimir_reporte(const char*reporte,int *DNIPacientes, int *codigo_distrito, int *anioNacimiento,
                    double *descuento,int n_pacientes,int *cantCitas,int *cantMedicinas,
                    double *pagoMedicinas) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimirEncabezado(write);
    imprimirEncabezado1(write);
    int i=0;
    double pagoTotal=0.0;
    while (i<n_pacientes) {
        write<<setw(5)<<""<<DevolverClasificacion(anioNacimiento[i]);
        write<<setw(10)<<""<<codigo_distrito[i];
        write<<setw(10)<<""<<DNIPacientes[i];
        write<<setw(10)<<""<<fixed<<setprecision(2)<<descuento[i];
        write<<setw(10)<<""<<cantCitas[i];
        write<<setw(10)<<""<<cantMedicinas[i];
        write<<setw(10)<<""<<pagoMedicinas[i]<<endl;
        i++;
        pagoTotal+=pagoMedicinas[i];
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"RESUMEN"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"PAGO TOTAL POR MEDICINAS: "<<pagoTotal<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

char DevolverClasificacion(int anio) {
    if (anio>=2019) return 'A';
    else if (anio>=2013 and anio<=2018) return 'B';
    else if (anio>=2006 and anio<=2012) return 'C';
    else if (anio>=1998 and anio<=2005) return 'D';
    else if (anio>1965 and anio<=1997) return 'E';
    else if (anio<=1965) return 'F';
}

void swapInt (int &a,int &b) {
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void swapDouble (double &a,double &b) {
    double aux;
    aux=a;
    a=b;
    b=aux;
}
int BuscarPaciente(int *DNIPacientes,int n_pacientes,int DNILeido) {
    int i=0;
    while (i<n_pacientes) {
        if (DNIPacientes[i]==DNILeido) {
            return i;
        }
        i++;
    }
    return -1;
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

int AlmacenarDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}