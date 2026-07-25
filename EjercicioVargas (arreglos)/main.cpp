#include "src/Funciones.hpp"

int main() {
    //CitasMedicas.txt
    int fecha_cita[MAX_CITAS]{};
    double descuento[MAX_CITAS]{};
    int duracion[MAX_CITAS]{};
    int codigos_Medicos[MAX_CITAS]{};
    int n_citasMedicas=0;
    cargar_citasMedicas("Datos/CitasMedicas.txt",fecha_cita,descuento,duracion,codigos_Medicos,n_citasMedicas);
    probar_citasMedicas("Reporte/reporte_prueba_citasMedicas.txt",fecha_cita,descuento,duracion,codigos_Medicos,n_citasMedicas);
    //Medicos.txt
    int codigos_medicos[MAX_MEDICOS]{};
    double Tarifas[MAX_MEDICOS]{};
    int n_medicos=0;
    cargar_Medicos("Datos/Medicos.txt",codigos_medicos,Tarifas,n_medicos);
    probar_Medicos("Reporte/reporte_prueba_Medicos.txt",codigos_medicos,Tarifas,n_medicos);
    //Medicinas.txt
    int codigo_medicina[MAX_MEDICINAS]{};
    double precio_medicina[MAX_MEDICINAS]{};
    int n_medicinas=0;
    cargar_Medicinas("Datos/Medicinas.txt",codigo_medicina,precio_medicina,n_medicinas);
    probar_Medicinas("Reporte/reporte_prueba_Medicinas.txt",codigo_medicina,precio_medicina,n_medicinas);
    return 0;
}