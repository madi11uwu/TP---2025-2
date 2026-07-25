#include "src/Funciones.hpp"

int main() {
    int anio=2023,ciclo=1;
    //cin>>anio>>c>>ciclo;
    //Alumnos.txt
    int codigo_alumnos[MAX_ALUMNOS]{};
    char escalas[MAX_ALUMNOS]{};
    int n_alumnos=0;
    cargar_alumnosOrdenado("Datos/Alumnos_lab6.txt", codigo_alumnos,
                          escalas, n_alumnos);
    //Cursos.txt
    int codigo_curso[MAX_CURSOS]{};
    char *nombreCurso[MAX_CURSOS]{};
    double NumCredito[MAX_CURSOS]{};
    int n_cursos=0;
    cargar_cursosOrdenado("Datos/Cursos_lab6.txt", codigo_curso,
                          nombreCurso, NumCredito, n_cursos);
    //Escalas.txt
    int year[MAX_ESCALAS]{};
    int semestre[MAX_ESCALAS]{};
    char Escalas[MAX_ESCALAS]{};
    double PrecioCredito[MAX_ESCALAS]{};
    int n_escalas=0;
    cargar_escalas("Datos/Escalas_lab6.txt", year, semestre,
                   Escalas, PrecioCredito, n_escalas);
    //Matricula.txt
    double cantCreditos[MAX_ALUMNOS]{};
    int cantCursos[MAX_ALUMNOS]{};
    double MontoPagado[MAX_ALUMNOS]{};
    llenarArreglos("Datos/Matricula_lab6.txt", anio, ciclo, codigo_alumnos,
                   escalas, n_alumnos, codigo_curso, NumCredito, n_cursos,
                   year, semestre,Escalas,
                   PrecioCredito, cantCreditos,n_escalas,
                   cantCursos,MontoPagado);
    imprimir_reporte("Reportes/Reporte","Datos/AlumnosNombres.txt", "Datos/AlumnosApellidos.txt",
                     codigo_alumnos, escalas, n_alumnos,cantCreditos,
                     cantCursos, MontoPagado,anio,ciclo);
    // int i=0;
    // while (i<n_cursos) {
    //     cout<<codigo_alumnos[i]<<endl;
    //     cout<<cantCursos[i]<<endl;
    //     cout<<MontoPagado[i]<<endl;
    //     cout<<cantCreditos[i]<<endl;
    //     i++;
    // }

    return 0;
}
