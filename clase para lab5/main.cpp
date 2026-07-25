#include "src/Funciones.hpp"

int main() {
    //Cadenas
    //Estatica
    char cadena[20]="Hola";
    //strlen
    cout<<strlen(cadena)<<endl;
    //strcat
    strcat(cadena," mundo");
    cout<<cadena<<endl;

    //Dinamica
    char *nombre;
    nombre=new char[20];
    strcpy(nombre,"Madison");
    cout<<nombre<<endl;
    //Lecturas
    char buffer[5];//Uno siempre para el fin de cadena (entonces solo se usan 4)
    // cin>>buffer;
    // cout<<buffer<<endl;
    //Comparacion
    int cmp=strcmp(cadena,"Hola"); //Devuelve el valor ASCII de los caracteres diferentes entre las cadenas
    cout<<cmp<<endl;
    return 0;
}

int busqueda_binaria(int dato_buscar,const int *arr,int n) {
    int limite_inferior=0,limite_superior=n-1;
    int punto_medio;
    while (true) {
        if (limite_inferior>limite_superior) return -1;
        punto_medio = (limite_superior+limite_inferior)/2;
        if (dato_buscar==arr[punto_medio]) return punto_medio;
        if (dato_buscar>arr[punto_medio]) {
            limite_inferior=punto_medio+1;
        }
        else
            limite_superior=punto_medio-1;
    }
}

//strlen(name): obtener el tamaño de una cadena
//strcpy(destino,origen): Los caracteres que está en buffer los va a copiar en cadena
//strcpy(cadena,buffer)
//Cuando acabe la función el buffer se va a borrar y la cadena se va a devolver
//libreria <cstring>