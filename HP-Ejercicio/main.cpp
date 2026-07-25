#include "src/Funciones.hpp"

int main() {
    struct NodoPersonaje *personaje;
    // cargarPersonajes("Datos/HarryPotterPhilosopherStone.csv",personaje);
    char oracion[30]="Ya fue TP.";
    char *str;
    str=new char[strlen(oracion)+1];
    strcpy(str,oracion);
    char oracionProcesada[30];
    int k=0;
    for (int i=0;str[i];i++) {
        if (isalpha(str[i]) or str[i]==' ') {
            oracionProcesada[k]=tolower(str[i]);
            k++;
        }
    }
    oracionProcesada[k]='\0';
    cout<<oracionProcesada<<endl;
    char *word;
    word=strtok(oracionProcesada," ");
    while (word) {
        cout<<word<<endl;
        word=strtok(nullptr," ");
    }
    return 0;
}