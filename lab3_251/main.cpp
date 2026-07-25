#include "src/Funciones.hpp"

int main() {
    procesar_datos_infracciones("Data/EmpresasRegistradas.txt","Data/InfraccionesCometidas",
                                "Data/TablaInfracciones.txt","Reporte/reporte.txt");
    return 0;
}