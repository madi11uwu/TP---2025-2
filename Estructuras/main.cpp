#include "src/VideoJuego.hpp"
#include <iostream>
using namespace std;

int main() {
    struct VideoJuego videojuego1;
    VideoJuego videojuego2;
    //Puedo colocar struct antes o no
    videojuego1.id=123;
    videojuego1.precio = 75.99;
    videojuego1.es_apto=true;
    videojuego1.fecha_lanzamiento = 20250915;
    videojuego1.titulo=asignar_str("Pokemon ZA");
    for (int i=0;i<5;i++) {
        videojuego1.dlcs[i]=asignar_str("DLC");
    }
    videojuego1.empresa_desarrolladora.cantidad_desarroladores=50;
    videojuego1.empresa_desarrolladora.nombre=asignar_str("NIATICS!");
    cout<<videojuego1.titulo<<endl;
    cout<<videojuego1.dlcs[3]<<endl;
    cout<<videojuego1.empresa_desarrolladora.nombre<<endl;
    return 0;
}

//Asignación estática
//videojuego2=videojuego1
//Datos prestados