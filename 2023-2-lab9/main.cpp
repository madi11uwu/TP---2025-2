#include "src/Funciones.hpp"
#include "src/Alumno.hpp"
#include "src/Curso.hpp"
#include "src/Escala.hpp"

int main() {
    // cout<<"Ingrese el semestre (año-ciclo): ";
    // char semestre[7];
    // cin>>semestre;
    char semestre[7];
    strcpy(semestre,"2023-1");
    //Escalas.csv
    struct Escala *escala;
    int n_escala=0;
    cargarEscalas("Datos/Escalas_lab9.csv",escala,n_escala);
    //Cursos.csv
    struct Curso *curso;
    int n_curso=0;
    cargarCursos("Datos/Cursos_lab9.csv",curso,n_curso);
    //Matricula.csv
    LeerMatricula("Datos/Matricula_lab9.vsc",curso,escala,n_escala,n_curso,semestre);

    return 0;
}
