#include "src/Funciones.hpp"

int main() {
    // char nombre_1[20];
    // char nombre_2[20];
    // cin>>nombre_1;
    // cout<<nombre_1<<endl;
    // nombre_1[0]=mayus(nombre_1[0]);
    // cout<<nombre_1<<endl;
    // //Largo Length str
    // int n=0;
    // for (int i=0;nombre_1[i];i++)n++;
    // cout<<n<<endl;
    char cadena[100]="erasmo/gomez-montoya";
    char *nombre=new char[strlen(cadena)+1];
    char *apellidos=new char[strlen(cadena)+1];
    int i=0,j=0;
    while (cadena[i]!='\0' and cadena[i]!='/') {
        nombre[i]=cadena[i]-32;
        i++;
    }
    nombre[i]='\0';
    if (cadena[i]=='/')i++;
    while (cadena[i]!='\0'){
        if (cadena[i]=='-')apellidos[j]=' ';
        if (cadena[i]!='-') apellidos[j]=cadena[i]-32;
        i++;
        j++;
    }
    apellidos[j]='\0';
    char *nombreCompleto=new char[300];
    strcpy(nombreCompleto,nombre);
    strcat(nombreCompleto," ");
    strcat(nombreCompleto,apellidos);
    cout<<nombreCompleto;
    return 0;
}

char *leer_cadena_exacta(ifstream &leer) {
    char *str,buffer[MAX_CARACTERES];
    leer>>buffer;
    if (leer.eof()) return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}