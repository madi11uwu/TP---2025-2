//
// Created by Madi on 11/09/2025.
//

#ifndef CLASETP_FUNCIONES_HPP
#define CLASETP_FUNCIONES_HPP
#include "Utils.hpp"
void leer_procesar_clientes_moviles(const char *file_name);
void apertura_archiv_lectura(ifstream &input,const char *file_name);
void lee_imprimir_datos_moviles(ifstream &input,ofstream &output);
#endif //CLASETP_FUNCIONES_HPP