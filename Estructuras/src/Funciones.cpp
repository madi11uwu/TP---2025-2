//
// Created by Madi on 6/11/2025.
//

#include "Funciones.hpp"

char * asignar_str(const char *orig) {
    char *str;
    str=new char[strlen(orig)+1];
    strcpy(str,orig);
    return str;
}
