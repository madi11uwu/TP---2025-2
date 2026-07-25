//
// Created by Madi on 6/11/2025.
//

#ifndef ESTRUCTURAS_VIDEOJUEGO_HPP
#define ESTRUCTURAS_VIDEOJUEGO_HPP
#include "Funciones.hpp"
#include "src/Empresa.hpp"
struct VideoJuego {
  int id;
  char *titulo;//Cadena Dinámico
  //char titulo[20]; //estático
  int fecha_lanzamiento;
  double precio;
  bool es_apto;
  char *dlcs[10];
  Empresa empresa_desarrolladora;
};
#endif //ESTRUCTURAS_VIDEOJUEGO_HPP