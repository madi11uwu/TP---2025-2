#include "src/Funciones.hpp"

int main() {
    struct NodoPersonaje *lista;
    // cargarPersonaje("Datos/HarryPotterPhilosopherStone.csv",lista);
    char oracion[50]="Anita Lava La Tina. Por favor.";
    char oracionProcesada[50];
    int k=0;
    for (int i=0;oracion[i];i++) {
        if (isalpha(oracion[i]) or oracion[i]==' ') {
            oracionProcesada[k]=tolower(oracion[i]);
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