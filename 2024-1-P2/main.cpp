#include "src/Funciones.hpp"

int main() {
    //Pacientes.txt
    int DNIPacientes[MAX_PACIENTES]{};
    int codigo_distrito[MAX_PACIENTES]{};
    int anioNacimiento[MAX_PACIENTES]{};
    double descuento[MAX_PACIENTES]{};
    int n_pacientes = 0;
    cargarPacientes("Datos/Pacientes.txt",DNIPacientes,codigo_distrito,
                    anioNacimiento,descuento,n_pacientes);
    probarPacientes("Reportes/Reporte_pruebaPacientes.txt",DNIPacientes,codigo_distrito,
                    anioNacimiento,descuento,n_pacientes);
    //Medicinas.txt
    int codigo_medicina[MAX_MEDICINAS]{};
    double precio_medicina[MAX_MEDICINAS]{};
    int n_medicina = 0;
    cargarMedicinas("Datos/Medicinas.txt",codigo_medicina,precio_medicina,n_medicina);
    probarMedicinas("Reportes/Report_prueba_medicinas.txt",codigo_medicina,precio_medicina,
                    n_medicina);
    //CitasMedicas.txt
    int cantCitas[MAX_PACIENTES]{};
    int cantMedicinas[MAX_PACIENTES]{};
    double pagoMedicinas[MAX_PACIENTES]{};
    GenerarArreglos("Datos/CitasMedicas.txt",DNIPacientes,codigo_distrito,
                    anioNacimiento,descuento,n_pacientes,codigo_medicina,
                    precio_medicina,n_medicina,cantCitas,cantMedicinas,pagoMedicinas);
    ordenarArreglos(DNIPacientes,codigo_distrito,anioNacimiento,
                    descuento,n_pacientes,cantCitas,cantMedicinas,
                    pagoMedicinas);
    imprimir_reporte("Reportes/Reporte.txt",DNIPacientes,codigo_distrito,anioNacimiento,
                    descuento,n_pacientes,cantCitas,cantMedicinas,
                    pagoMedicinas);
    return 0;
}