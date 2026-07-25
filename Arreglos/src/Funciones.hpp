//
// Created by Madi on 26/09/2025.
//

#ifndef ARREGLOS_FUNCIONES_HPP
#define ARREGLOS_FUNCIONES_HPP
#include "Utils.hpp"
void printArray(int* arr, int size);
int linearSearch(int *arr, int size, int target);
int findMax(int *arr, int size);
void bubbleSort(int *arr, int size) ;
void reverseArray(int *arr, int size) ;
void selectionSort(int *arr, int n) ;
void apertura_archivo_lectura(ifstream& input, const char* file_name);
void leer_codigos(int *codigos,int &n,const char* file_name);
#endif //ARREGLOS_FUNCIONES_HPP
