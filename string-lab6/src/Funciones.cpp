//
// Created by Madi on 25/10/2025.
//

#include "Funciones.hpp"
char mayus(char c) {
    if (c>='a' and c<='z') return c-32;
    return c;
}

//0->false->\0->nullptr->null->enpty!

void modificar_cadena(char *cadena) {
    for (int i=0;cadena[i];i++)
        if (cadena[i]=='_')cadena[i]=' ';
}

//erasmo/gomez-Montoya
//Resultado pedido:
//Gomez Montoya, Erasmo
//se concatena con strcat

//Reserva de memoria dinámica
//str=new char[strlen(buffer)+1]; Indicarle a C++ que quiero una cantidad
//de este tipo de dato nueva en memoria

//Estático:
//int codigos[50];
//Dinámico:
//int *codigos;
//codigos=new int[50];