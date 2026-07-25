#include "src/Funciones.hpp"

int main() {
    int anio=2023,ciclo=1;
    //Cursos.csv
    struct NodoCurso *listaCurso;
    cargarCursos("Datos/Cursos.csv",listaCurso);
    //Escalas.csv
    struct NodoEscala *listaEscala;
    cargarEscalas("Datos/Escalas.csv",listaEscala);
    //alumnos.csv
    struct NodoAlumno *listaAlumno;
    cargarAlumnos("Datos/Alumnos.csv",listaAlumno,listaEscala);
    ImprimirReporte("Reportes/ReporteInicialAlumnos.txt",listaAlumno,anio,ciclo);
    //Matricula.txt
    llenarAlumnos("Datos/Matricula.txt", listaEscala, listaAlumno, listaCurso,
                  anio, ciclo);

    return 0;
}
