#include "src/Funciones.hpp"

int main() {
    int anio=2023;
    int ciclo=1;
    //Cursos.csv
    struct NodoCurso *listaCurso;
    cargarCursos("Datos/Cursos.csv",listaCurso);
    //Escalas.csv
    struct NodoEscala *listaEscala;
    cargarEscala("Datos/Escalas.csv",listaEscala);
    //alumnos.csv
    struct NodoAlumno *listaAlumno;
    cargarAlumnos("Datos/Alumnos.csv",listaAlumno);
    imprimirReporte("Reportes/ReporteInicialAlumnos.txt", listaAlumno, "INSTITUCION EDUCATIVA TP",
                    "DETALLE PRELIMINAR DE ALUMNOS", 'N', anio, ciclo);
    //Matricula.txt
    CompletarAlumnos("Datos/Matricula.txt", listaAlumno, listaCurso, listaEscala,
                     anio, ciclo);
    EliminarNodos(listaAlumno,ciclo,anio);
    imprimirReporte("Reportes/ReporteFinalAlumnos.txt", listaAlumno, "INSTITUCION EDUCATIVA TP",
                    "DETALLE DE PAGOS REALIZADO POR CICLO", 'S', anio, ciclo);

    return 0;
}
