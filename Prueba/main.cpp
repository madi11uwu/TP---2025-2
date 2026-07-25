#include "Funciones.hpp"
#include "cmake-build-debug/Persona.hpp"


int main() {
    struct Persona persona;
    int n_personas=0;
    cargarPersona("Datos/Nombres.txt",persona,n_personas);
    return 0;
}
