//
// Created by Madi on 12/10/2025.
//

#include "Funciones.hpp"

void GenerarReporteMedicina(const char *citas, const char *medicinas, const char *medicos,
                            const char *pacientes, const char *reporte) {
    ifstream leer_citas;
    ifstream leer_medicinas;
    ifstream leer_pacientes;
    ifstream leer_medicos;
    ofstream write;
    apertura_lectura(citas,leer_citas);
    apertura_lectura(medicinas,leer_medicinas);
    apertura_lectura(pacientes,leer_pacientes);
    apertura_lectura(medicos,leer_medicos);
    aperuta_escritura(reporte,write);
    imprimir_reporte(leer_citas,leer_medicos,leer_medicinas,leer_pacientes,write);
    leer_citas.close();
    leer_medicinas.close();
    leer_pacientes.close();
    leer_medicos.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void aperuta_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<"EMPRESA DE SALUD S.A."<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<"DETALLE DE CITAS MEDICAS POR PACIENTE"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_reporte(ifstream &leer_citas, ifstream &leer_medicos, ifstream &leer_medicinas,
                      ifstream &leer_pacientes,ofstream &write) {
    int DNI;
    double descuento,pagoTotal;
    imprimir_encabezado(write);
    while (true) {
        leer_pacientes>>DNI;
        if (leer_pacientes.eof())break;
        imprimirDatosEstaticos(leer_pacientes,write,DNI,descuento);
        imprimir_linea(ANCHO_REPORTE,'-',write);
        write<<"CITAS: "<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        imprimirParteDinamica(leer_citas,leer_medicinas,leer_medicos,write,DNI,descuento,pagoTotal);
        write<<"PAGO TOTAL DEL PACIENTE: "<<fixed<<setprecision(2)<<pagoTotal<<endl;
        imprimir_linea(ANCHO_REPORTE,'=',write);
    }
}

void imprimirParteDinamica(ifstream &leer_citas,ifstream &leer_medicinas,
                            ifstream &leer_medicos,ofstream &write,int DNI,
                            double descuento,double &pagoTotal) {
    leer_citas.clear();
    leer_citas.seekg(0,ios::beg);
    int fecha,DNILeido,horaI,horaF,duracion,codigo_medico,codigo_medicina,cantidad;
    double pago,precio,pagoMedicinas,pagoMedicina;
    pagoTotal=0.0;
    char c;
    while (true) {
        fecha = AlmacenarFecha(leer_citas);
        if (leer_citas.eof())break;
        leer_citas>>DNILeido;
        if (DNILeido==DNI) {
            horaI=AlmacenarDuracion(leer_citas);
            horaF=AlmacenarDuracion(leer_citas);
            duracion=horaF-horaI;
            leer_citas>>codigo_medico;
            imprimirPrimerEncabezadoDinamico(write);
            imprimirPrimeraParteDinamica(fecha,duracion,codigo_medico,leer_medicos,write,pago,descuento);
            imprimirSegundoEncabezadoDinamico(write);
            int nro_medicina=1;
            pagoMedicinas=0.0;
            while (true) {
                c=leer_citas.get();
                if (c=='\n')break;
                leer_citas>>codigo_medicina>>cantidad;
                imprimirSegundaParteDinamica(write,codigo_medicina,cantidad,nro_medicina,pagoMedicina,
                                            leer_medicinas,descuento);
                pagoMedicinas+=pagoMedicina;
                nro_medicina++;
            }
            write<<"Pago total por medicinas: "<<pagoMedicinas<<endl;
            write<<"Pago total: "<<pago+pagoMedicinas<<endl;
            imprimir_linea(ANCHO_REPORTE,'-',write);
            pagoTotal+=pago+pagoMedicinas;
        }
        else {
            leer_citas.ignore(300,'\n');
            continue;
        }
    }
}

void imprimirSegundaParteDinamica(ofstream &write,int codigo_medicina,
                                    int cantidad,int nro_medicina,double &pago,
                                    ifstream &leer_medicina,double descuento) {
    double precio;
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<setw(2)<<setfill('0');
    write<<nro_medicina<<setfill(' ');
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<codigo_medicina;
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
    BuscarDescripcionYPrecio(leer_medicina,write,codigo_medicina,precio);
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<cantidad;
    pago=precio*cantidad*(100-descuento/2)/100.0;
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<pago<<endl;
}
void BuscarDescripcionYPrecio(ifstream &leer_medicina,ofstream &write,int codigo_medicina,
                            double &precio) {
    leer_medicina.clear();
    leer_medicina.seekg(0,ios::beg);
    int codigoLeido;
    while (true) {
        leer_medicina>>codigoLeido;
        if (leer_medicina.eof()) break;
        if (codigoLeido==codigo_medicina) {
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+40))<<"";
            leerNombres(leer_medicina,write,'D',' ');
            leer_medicina>>precio;
            write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<precio;
        }
        else {
            leer_medicina.ignore(300,'\n');
            continue;
        }
    }
}
void imprimirPrimeraParteDinamica(int fecha,int duracion,int codigo_medico,ifstream &leer_medicos,
                                ofstream &write,double &pago,double descuento) {
    double tarifa;
    imprimirFecha(fecha,write);
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<"";
    imprimir_duracion(duracion,write);
    BuscartarifaEImprimirNombreYEspecialidad(leer_medicos,codigo_medico,tarifa,write);
    pago=tarifa*(duracion/3600.0)*(100-descuento)/100.0;
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<pago<<endl;
}
void BuscartarifaEImprimirNombreYEspecialidad(ifstream &leer_medicos,int codigo_medico,double &tarifa,ofstream &write) {
    leer_medicos.clear();
    leer_medicos.seekg(0,ios::beg);
    int codigoLeido;
    while (true) {
        leer_medicos>>codigoLeido;
        if (leer_medicos.eof()) break;
        if (codigoLeido==codigo_medico) {
            leerNombres(leer_medicos,write,'N','/');
            write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<"";
            leerNombres(leer_medicos,write,'D',' ');
            leer_medicos>>tarifa;
        }
        else {
            leer_medicos.ignore(300,'\n');
            continue;
        }
    }
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimirFecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void imprimirPrimerEncabezadoDinamico(ofstream &write) {
    write<<"Fecha";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"Duracion";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"Medico";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"Especialidad";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"Pago por cita"<<endl;
}

void imprimirSegundoEncabezadoDinamico(ofstream &write) {
    write<<"Medicinas recetas:"<<endl;
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"No.";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"Codigo";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"Descripcion";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"Cantidad";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"Precio";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"Pago"<<endl;
}
void imprimirDatosEstaticos(ifstream &leer_pacientes,ofstream &write,int DNI,double &descuento) {
    int codigo,año;
    write<<"PACIENTE: "<<DNI;
    write<<" - ";
    leerNombres(leer_pacientes,write,'N',']');
    leer_pacientes>>codigo>>año>>descuento;
    write<<setw(3)<<""<<"Año de nacimiento: "<<año;
    write<<setw(3)<<""<<"%Descuento: "<<descuento<<endl;
}

void leerNombres(ifstream &leer,ofstream &write,char c,char c1) {
    leer>>ws;
    char car;
    if (c=='N') {
        leer>>car;
        while (true) {
            car=leer.get();
            if (car==c1)break;
            write.put(car);
        }
    }
    else if (c=='D') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car=='_')car=' ';
            write.put(car);
        }
    }
}

int AlmacenarDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}