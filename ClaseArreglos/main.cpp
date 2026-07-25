#include "src/Funciones.hpp"

int main() {
    //int size=5;
    //int codigos[5] = {20082060,20082131,20240519,20240340,20240556};
    //printArray(codigos,size);
    int codigos[MAX_CODIGOS]{};
    int n = 0;
    leer_codigos(codigos,n,"Data/codigos.txt");
    cout<<"La cantidad de codigos es: "<<n<<endl;
    printArray(codigos,n);
    int pos = linearSearch(codigos,n,20241182);
    if (pos!= -1) {
        cout<<"Codigo encontrado: "<<codigos[pos]<<endl;
    }
    else {
        cout<<"Codigo no encontrado"<<endl;
    }
    return 0;
}

//Linear Search
//int linearSearch (int *arr,int size,int target){
//
//
//
//}