//
// Created by Madi on 27/09/2025.
//

#include "Funciones.hpp"

void apertura_lectura(const char *file, ifstream &leer) {
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

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

int AlmacenarHora(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void imprimir_hora(ofstream &write, int Hora) {
    write<<setw(2)<<setfill('0')<<Hora/3600<<":"<<setw(2)<<setfill('0')<<(Hora%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(Hora%3600)%60;
    write<<setfill(' ');
}

void cargar_citasMedicas(const char *citas, int *fecha_cita, double *descuento, int *duracion,
                         int *codigos_Medicos,int &n_citasMedicas) {
    ifstream leer_citas;
    apertura_lectura(citas,leer_citas);
    int fechaCita,horaInicial,horaFinal;
    while (true) {
        fechaCita = AlmacenarFecha(leer_citas);
        if (leer_citas.eof())break;
        ignorar(leer_citas,' ');
        fecha_cita[n_citasMedicas]=fechaCita;
        leer_citas>>descuento[n_citasMedicas];
        horaInicial = AlmacenarHora(leer_citas);
        horaFinal = AlmacenarHora(leer_citas);
        duracion[n_citasMedicas]=horaFinal-horaInicial;
        leer_citas>>codigos_Medicos[n_citasMedicas];
        ignorar(leer_citas,'\n');
        n_citasMedicas++;
    }
}

void ignorar(ifstream &leer,char car) {
    char c;
    leer>>ws>>c;
    while (true) {
        c=leer.get();
        if (c==car)break;
    }
}

void cargar_Medicos(const char *medicos, int *codigos_medicos, double *Tarifas, int &n_medicos) {
    ifstream leer_Medicos;
    apertura_lectura(medicos,leer_Medicos);
    int c_medico;
    while (true) {
        leer_Medicos>>c_medico;
        if (leer_Medicos.eof())break;
        ignorar(leer_Medicos,'/');
        ignorar(leer_Medicos,' ');
        leer_Medicos>>Tarifas[n_medicos];
        codigos_medicos[n_medicos]=c_medico;
        n_medicos++;
    }
}

void probar_Medicos(const char *salida_medicos, int *codigos_medicos, double *Tarifas, int n_medicos) {
    ofstream write;
    apertura_escritura(salida_medicos,write);
    int i=0;
    write<<"Medicos: "<<endl;
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/2)<<""<<"TARIFA"<<endl;
    while (i<n_medicos) {
        write<<setw(ANCHO_REPORTE/2)<<""<<codigos_medicos[i];
        write<<setw(ANCHO_REPORTE/2)<<""<<Tarifas[i]<<endl;
        i++;
    }
}

void cargar_Medicinas(const char *medicinas, int *codigo_medicina, double *precio_medicina, int &n_medicinas) {
    int c_medicina;
    ifstream leer_Medicina;
    apertura_lectura(medicinas,leer_Medicina);
    while (true) {
        leer_Medicina>>c_medicina;
        if (leer_Medicina.eof())break;
        ignorar(leer_Medicina,' ');
        leer_Medicina>>precio_medicina[n_medicinas];
        codigo_medicina[n_medicinas]=c_medicina;
        n_medicinas++;
    }
}

void probar_Medicinas(const char *medicinas, int *codigo_medicina, double *precio_medicina, int n_medicinas) {
    int i=0;
    ofstream write;
    apertura_escritura(medicinas,write);
    write<<"Medicinas: "<<endl;
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/2)<<""<<"PRECIO"<<endl;
    while (i<n_medicinas) {
        write<<setw(ANCHO_REPORTE/2)<<""<<codigo_medicina[i];
        write<<setw(ANCHO_REPORTE/2)<<""<<precio_medicina[i]<<endl;
        i++;
    }
    write.close();
}

void probar_citasMedicas(const char *salida, int *fecha_cita, double *descuento, int *duracion,
                         int *codigos_Medicos,int n_citasMedicas) {
    ofstream write;
    apertura_escritura(salida,write);
    int i=0;
    write<<"Citas Medicas: "<<endl;
    write<<setw(ANCHO_REPORTE/4)<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/4)<<""<<"DESCUENTO";
    write<<setw(ANCHO_REPORTE/4)<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO MEDICO"<<endl;
    while (i<n_citasMedicas) {
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimir_fecha(write,fecha_cita[i]);
        write<<setw(ANCHO_REPORTE/4)<<""<<descuento[i];
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimir_hora(write,duracion[i]);
        write<<setw(ANCHO_REPORTE/4)<<""<<codigos_Medicos[i]<<endl;
        i++;
    }
    write.close();
}
