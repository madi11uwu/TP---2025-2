#include "src/Funciones.hpp"
#include "src/Facultad .hpp"
#include "src/Alumno.hpp"

int main() {
    struct Alumno *arrAlumnos;
    int n_alumnos=0;
    cargarAlumnos("Datos/Calificaciones.txt", arrAlumnos,
                  n_alumnos);
    llenarAlumnos("Datos/Alumnos.csv",arrAlumnos,n_alumnos);
    llenarAlumnosPorDos("Datos/Facultades.txt",arrAlumnos,n_alumnos);

    return 0;
}
