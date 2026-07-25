#include "src/Funciones.hpp"
#include "src/Alumno.hpp"
#include "src/Curso.hpp"
#include "src/Escala.hpp"

int main() {
    char semestre[7];
    // cout<<"Ingrese el semestre: ";
    // cin>>semestre;
    strcpy(semestre, "2023-1");
    struct Alumno *alumno;
    int n_alumno=0;
    cargarAlumnos("Datos/Alumnos_lab8.csv",alumno,n_alumno);
    struct Curso *curso;
    int n_curso=0;
    cargarCursos("Datos/Cursos_lab8.csv",curso,n_curso);
    struct Escala *escala;
    int n_escala=0;
    cargarEscalas("Datos/Escalas_lab8.csv",escala,n_escala);
    //Matricula.txt
    completarCursos("Datos/Matricula_lab8.csv", curso, n_curso,
                    semestre, escala, n_escala,
                    alumno, n_alumno);
    ordenarCursos(curso,n_curso);
    imprimir_reporte("Reportes/Reporte", escala, curso, alumno,
                     n_escala, n_curso, n_alumno, semestre);
    return 0;
}
