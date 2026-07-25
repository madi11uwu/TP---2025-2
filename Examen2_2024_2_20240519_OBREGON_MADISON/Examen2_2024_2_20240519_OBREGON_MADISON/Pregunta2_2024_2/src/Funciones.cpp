//
// Created by Madi on 30/11/2025.
//

#include "Funciones.hpp"

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

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}

int almacenarHora(ifstream &read) {
    int hh,mm;
    char c;
    read>>hh>>c>>mm;
    return (hh*60+mm);
}

void imprimirHora(int hora, ofstream &write) {
    write<<setw(2)<<setfill('0')<<hora/60<<":";
    write<<setw(2)<<setfill('0')<<hora%60;
    write<<setfill(' ');
}

void cargarPalabra(const char *str, struct Palabra *lexicon, int &n_lexicon) {
    ifstream read;
    apertura_lectura(str,read);
    char *palabra;
    while (true) {
        palabra=leer_cadena(20,',',read);
        if (read.eof())break;
        lexicon[n_lexicon].texto=palabra;
        lexicon[n_lexicon].polaridad=leer_int(read);
        n_lexicon++;
    }
}

void cargarPlato(const char *str, struct Plato *&plato, int &n_platos) {
    ifstream read;
    apertura_lectura(str,read);
    plato=new struct Plato[200]{};
    char *codigo;
    while (true) {
        codigo=leer_cadena(10,',',read);
        if (read.eof())break;
        plato[n_platos].codigo=codigo;
        plato[n_platos].nombre=leer_cadena(40,',',read);
        plato[n_platos].precio=leer_double(read);
        n_platos++;
    }
}

int BuscarPlato(char * codigo, struct Plato * plato,int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(codigo, plato[i].codigo)==0) return i;
    }
    return -1;
}

void cargarAtencion(const char *str, struct Atencion *atenciones,
                    int &n_atencion, struct Plato *plato,
                    int n_platos) {
    ifstream read;
    apertura_lectura(str, read);
    char c;
    char CodPlato[7];
    int numAtencion, hora, cantidad, posPlato;
    while (true) {
        read >> numAtencion;
        if (read.eof())break;
        hora = almacenarHora(read);
        atenciones[n_atencion].codigo = numAtencion;
        atenciones[n_atencion].hora = hora;
        atenciones[n_atencion].platos_atendidos = new struct Plato[20]{};
        atenciones[n_atencion].comentarios = new struct Comentario[20]{};
        while (true) {
            read >> CodPlato >> cantidad;
            posPlato = BuscarPlato(CodPlato, plato,n_platos);
            if (posPlato!=-1) {
                int n=atenciones[n_atencion].cantidad_platos;
                atenciones[n_atencion].platos_atendidos[n].cantidad=cantidad;
                atenciones[n_atencion].platos_atendidos[n].codigo=asignar_cadena(CodPlato);
                atenciones[n_atencion].platos_atendidos[n].nombre=asignar_cadena(plato[posPlato].nombre);
                atenciones[n_atencion].platos_atendidos[n].precio=plato[posPlato].precio;
                atenciones[n_atencion].total_venta+=cantidad*plato[posPlato].precio;
                atenciones[n_atencion].cantidad_platos++;
            }
            c = read.get();
            if (c == '\n')break;
        }
        n_atencion++;
    }
}

char * asignar_cadena(const char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

int BuscarAtencion(int num_atencion, struct Atencion * atencion, int n_atencion) {
    for (int i = 0; i < n_atencion; i++) {
        if (atencion[i].codigo==num_atencion) return i;
    }
    return -1;
}

char * PreProcesar(char * oracion) {
    char *str;
    str=new char[strlen(oracion)+1];
    strcpy(str,oracion);
    for (int i=0;str[i];i++) {
        if (str[i]>='A' and str[i]<='Z') str[i]+=32;
        if (!esMinusOMayus(str[i]) and str[i]!=' ') {
            for (int j=i;str[j];j++) {
                str[j]=str[j+1];
            }
            i--;
        }
    }
    return str;
}

bool esMinusOMayus(char c) {
    if(c>='A' and c<='Z' or c>='a' and c<='z') return true;
    else return false;
}

int BuscarLexicon(struct Palabra * palabra, char * word, int n_lexicon) {
    for (int i = 0; i < n_lexicon; i++) {
        if (strcmp(word,palabra[i].texto)==0) return i;
    }
    return -1;
}

void completarPalabras(struct Comentario & comentario, struct Palabra * palabra, int n_lexicon, char * oracion_procesada) {
    char *word;
    int posLexicon;
    word=strtok(oracion_procesada," ");
    while (word) {
        int n=comentario.cantidad_palabras;
        posLexicon=BuscarLexicon(palabra,word,n_lexicon);
        if (posLexicon!=-1) comentario.palabras[n].polaridad=palabra[posLexicon].polaridad;
        else comentario.palabras[n].polaridad=0;
        comentario.polaridad_total+=comentario.palabras[n].polaridad;
        comentario.palabras[n].texto=asignar_cadena(word);
        word=strtok(nullptr," ");
        comentario.cantidad_palabras++;
    }
}

void imprimirReporte(const char *str, struct Atencion *atencions, int n_atencion) {
    ofstream write;
    apertura_escritura(str,write);
    write<<setw((120-strlen("EMPRESA DE REPARTOS A DOMICILIO TP S.A."))/2)<<"";
    write<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((120-strlen("RELACION DE ATENCIONES"))/2)<<"";
    write<<"RELACION DE ATENCIONES"<<endl;
    imprimirLinea(120,'=',write);
    for (int i = 0; i < n_atencion; i++) {
        write<<"No. ATENCION "<<atencions[i].codigo<<setw(10)<<"";
        write<<"Atendido a las: ";
        imprimirHora(atencions[i].hora,write);
        write<<endl;
        imprimirLinea(120,'-',write);
        for (int j = 0; j < atencions[i].cantidad_platos; j++) {
            write<<atencions[i].platos_atendidos[j].codigo<<")"<<setw(2)<<"";
            write<<atencions[i].platos_atendidos[j].nombre<<setw(5)<<"";
            write<<atencions[i].platos_atendidos[j].precio<<setw(5)<<"";
            write<<atencions[i].platos_atendidos[j].cantidad<<setw(5)<<"";
            write<<atencions[i].platos_atendidos[j].cantidad*atencions[i].platos_atendidos[j].precio<<endl;
        }
        write<<"Precio total: "<<atencions[i].total_venta<<endl;
        write<<"COMENTARIOS: "<<endl;
        int polaridad=0;
        for (int k=0;k<atencions[i].cantidad_comentarios;k++) {
            write<<atencions[i].comentarios[k].texto<<endl;
            polaridad+=atencions[i].comentarios[k].polaridad_total;
        }
        write<<"Polaridad total de los comentarios: "<<polaridad<<endl;
        imprimirLinea(120,'=',write);
    }
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void CompletarAtencion(const char *str, struct Atencion *atencions,
                       struct Palabra *lexicon, int n_atencion,
                       int n_lexicon) {
    ifstream read;
    apertura_lectura(str, read);
    int numAtencion,posAtencion;
    char *oracion,*oracionProcesada;
    while (true) {
        numAtencion = leer_int(read);
        if (read.eof())break;
        posAtencion=BuscarAtencion(numAtencion,atencions,n_atencion);
        if (posAtencion!=-1) {
            int n=atencions[posAtencion].cantidad_comentarios;
            oracion=leer_cadena(120,'\n',read);
            atencions[posAtencion].comentarios[n].texto=oracion;
            oracionProcesada=PreProcesar(oracion);
            atencions[posAtencion].comentarios[n].pre_procesado=oracionProcesada;
            completarPalabras(atencions[posAtencion].comentarios[n],lexicon,n_lexicon,oracionProcesada);
            atencions[posAtencion].cantidad_comentarios++;
        }
    }
}
