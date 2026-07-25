//
// Created by Madi on 9/11/2025.
//

#include "Funciones.hpp"

void cargar_reproducciones(const char *repro, int *arrFechaRepro, char **arrNombreCanal, char **arr_codigo_categoria,
    double *arr_rating, double *arr_tasa, int *arr_duracion, int &n_reproducciones) {
    ifstream leer_repro;
    apertura_lectura(repro, leer_repro);
    int fecha;
    while (true) {
        fecha=almacenarFecha(leer_repro);
        if (leer_repro.eof())break;
        arrFechaRepro[n_reproducciones] = fecha;
        arrNombreCanal[n_reproducciones] = leer_cadena_exacta(leer_repro);
        arr_codigo_categoria[n_reproducciones] = leer_cadena_exacta(leer_repro);
        leer_repro>>arr_rating[n_reproducciones];
        leer_repro>>arr_tasa[n_reproducciones];
        arr_duracion[n_reproducciones]=almacenarDuracion(leer_repro);
        n_reproducciones++;
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

void imprimir_linea(char c, int n, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

int almacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

int almacenarDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void imprimir_fecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_duracion(int duracion, ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

char * leer_cadena_exacta(ifstream &leer) {
    char buffer[MAX_CARACTERES];
    char *cadena;
    leer>>buffer;
    if (leer.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void probar_reproducciones(const char *file_name, int *arrFechaRepro, char **arr_nombre_canal,
                           char **arr_codigo_categoria,
                           double *arr_rating, double *arr_tasa,
                           int *arr_duracion, int n_reproducciones) {
    ofstream write;
    apertura_escritura(file_name,write);
    write<<"REPRODUCCIONES.TXT"<<endl;
    imprimir_linea('=',ANCHO_REPORTE,write);
    write<<"FECHA"<<setw(5)<<""<<"NOMBRE CANAL";
    write<<setw(5)<<""<<"CATEGORIA";
    write<<setw(5)<<""<<"RATING";
    write<<setw(5)<<""<<"TASA DROP OFF";
    write<<setw(5)<<""<<"DURACION"<<endl;
    for (int i = 0; i < n_reproducciones; i++) {
        imprimir_fecha(arrFechaRepro[i],write);
        write<<setw(5)<<""<<arr_nombre_canal[i];
        write<<setw(5)<<""<<arr_codigo_categoria[i];
        write<<setw(5)<<""<<arr_rating[i];
        write<<setw(5)<<""<<arr_tasa[i];
        write<<setw(5)<<"";
        imprimir_duracion(arr_duracion[i],write);
        write<<endl;
    }
}

void cargar_categorias(const char *file, char **arrCodCategoria,
                       char **arrnombre_categoria, int &n_categoria) {
    ifstream read;
    apertura_lectura(file,read);
    char *codigo;
    while (true) {
        codigo = leer_cadena_exacta(read);
        if (read.eof()) break;
        arrCodCategoria[n_categoria] = codigo;
        arrnombre_categoria[n_categoria] = leer_cadena_exacta(read);
        n_categoria++;
    }
}

void probar_categorias(const char *reporte, char **arrCodCategoria,
                       char **arrnombre_categoria, int n_categoria) {
    ofstream write;
    apertura_escritura(reporte,write);
    write<<"CATEGORIAS.TXT"<<endl;
    imprimir_linea('=',ANCHO_REPORTE,write);
    write<<"CODIGO CATEGORIA"<<setw(5)<<""<<"NOMBRE CATEGORIA"<<endl;
    for (int i = 0; i < n_categoria; i++) {
        write<<arrCodCategoria[i];
        write<<setw(5)<<""<<arrnombre_categoria[i]<<endl;
    }
}

void generaArchivoEnlace(char *categoria, char *&nombArch, char *&enlace) {
    char *copiaCadena,*cadena1,*cadena2;
    bool inicioPalabra=true;
    cadena1=new char[strlen("Reportes/")+1];
    nombArch=new char[strlen("Reportes/")+strlen(categoria)+5];
    cadena2=new char[strlen("https://Laboratorio06_2025_2/ArchivosDeReporte/")+1];
    enlace=new char[strlen("https://Laboratorio06_2025_2/ArchivosDeReporte/")+strlen(categoria)+2];
    copiaCadena = new char[strlen(categoria) + 1];
    strcpy(copiaCadena,categoria);
    for (int i = 0;copiaCadena[i]; i++) {
        if (inicioPalabra) {
            inicioPalabra=false;
            if (copiaCadena[i]>='a' and copiaCadena[i]<='z') copiaCadena[i]=copiaCadena[i]-32;
        }
        else {
            if (copiaCadena[i]=='_') inicioPalabra=true;
        }
    }
    strcpy(cadena1,"Reportes/");
    strcpy(cadena2,"https://Laboratorio06_2025_2/ArchivosDeReporte/");
    strcpy(nombArch,cadena1);
    strcat(nombArch,copiaCadena);
    strcat(nombArch,".txt");
    strcpy(enlace,cadena2);
    strcat(enlace,copiaCadena);
}

void imprimir_reportes(char **arrCodCategoria, char **arrnombreCategoria,
                       int *arr_fecha_repro,char **arrCodigoCategoria,
                       char **arr_nombre_canal, double *arr_rating,
                       double *arr_tasa, int *arr_duracion, int n_categoria,
                       int n_reproducciones) {
    char *nombArch;
    char *enlace;
    for (int i = 0; i < n_categoria; i++) {
        generaArchivoEnlace(arrnombreCategoria[i],nombArch,enlace);
        imprimir_reporte(nombArch, arrCodCategoria[i], arr_fecha_repro,
                         arr_nombre_canal, arrnombreCategoria[i], enlace,
                         arr_rating, arr_tasa, arr_duracion, n_reproducciones,
                         arrCodigoCategoria);
    }
}

void imprimir_reporte(char *nombArch,char *categoria, int *arr_fecha_repro,
                      char **arr_nombre_canal, char *nombreCategoria,
                      char *enlace, double *arr_rating,
                      double *arr_tasa, int *arr_duracion,
                      int n_reproducciones,char **arrCodigoCategoria) {
    ofstream write;
    apertura_escritura(nombArch,write);
    double sumaRating=0.0,sumaTasa=0.0;
    int sumaDuracion=0,totalCategoria=0;
    write<<"Codigo: "<<categoria<<endl;
    write<<"Nombre: "<<nombreCategoria<<endl;
    write<<"Enlace: "<<enlace<<endl;
    write<<"REPRODUCCIONES: "<<endl;
    imprimir_linea('=',ANCHO_REPORTE,write);
    imprimir_encabezado(write);
    for (int i=0;i<n_reproducciones;i++) {
        if (strcmp(arrCodigoCategoria[i],categoria)==0) {
            imprimir_fecha(arr_fecha_repro[i],write);
            write<<setw(10)<<""<<arr_nombre_canal[i];
            write<<setw(10)<<""<<arr_rating[i];
            write<<setw(10)<<""<<arr_tasa[i];
            write<<setw(10)<<"";
            imprimir_duracion(arr_duracion[i],write);
            write<<endl;
            sumaRating+=arr_rating[i];
            sumaTasa+=arr_tasa[i];
            sumaDuracion+=arr_duracion[i];
            totalCategoria++;
        }
    }
    imprimir_estadisticas(sumaDuracion,totalCategoria,sumaRating,sumaTasa,write);
    write.close();
}

void imprimir_estadisticas(int sumaDuracion, int totalCategoria,
                           double sumaRating, double sumaTasa,
                           ofstream &write) {
    imprimir_linea('=',ANCHO_REPORTE,write);
    write<<"PROMEDIO DE RATING: "<<sumaRating/totalCategoria<<endl;
    write<<"PROMEDIO DE DROP-OFF: "<<sumaTasa/totalCategoria<<endl;
    write<<"DURACION TOTAL: ";
    imprimir_duracion(sumaDuracion,write);
}
void imprimir_encabezado(ofstream &write) {
    write<<"FECHA";
    write<<setw(10)<<""<<"CANAL";
    write<<setw(10)<<""<<"RATING";
    write<<setw(10)<<""<<"DROP-OFF";
    write<<setw(10)<<""<<"DURACION"<<endl;
}