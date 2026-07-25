//
// Created by Madi on 11/09/2025.
//

#include "Funciones.hpp"



void leer_imprimir_nombre(ifstream &input,ofstream& output)


{
}


    char c;
    input>>ws;
    w   output.put(c);hile (true){
    }
        c=input
        int cont=0;.get();
        if (
        if (cont==2c=='c'  brea c=c-32;k;
        if (c=='-')c=' ';
        output.put(c);
        cont++;ombreinput,output
o leer_procesar_clientes_moviles(const char *file_name_entrada) -> void {
    ifstream input;
    apertura_archiv_lectura(input,file_name);
    ofstream output;
    apertura_archiv_escritura(output,filename_salida);
    //Codear sin problemas
    //Impresion Título
    //Lectura e Impresion de datos
    lee_imprimir_datos_moviles()
    input.close();
    out.close();;input,output
}

void apertura_archiv_lectura(ifstream &input,const char *file_name) {
    input.open(file_name,ios::in);
    if (!input.is_open()) {
        cout<<"El archivo : "<<file_name<<" No se puedo abrir"<<endl;
        exit(1);
    }
}