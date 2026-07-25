#include "src/Funciones.hpp"

int main() {
    //Canales.txt
    int fechaCreacion[MAX_CANALES]{};
    char c_canal[MAX_CANALES]{};
    int int_canal[MAX_CANALES]{};
    double rating_canal[MAX_CANALES]{};
    int n_canales = 0;
    cargarCanales("Datos/Canales.txt",fechaCreacion,c_canal,int_canal,rating_canal,n_canales);
    probarCanales("Reportes/reporte_prueba_canales.txt",fechaCreacion,c_canal,int_canal,rating_canal,n_canales);
    //Etiquetas.txt
    int etiquetas[MAX_ETIQUETAS]{};
    int duracion[MAX_ETIQUETAS]{};
    int n_etiquetas = 0;
    cargarEtiquetas("Datos/Etiquetas.txt",etiquetas,duracion,n_etiquetas);
    probarEtiquetas("Reportes/reporte_prueba_etiquetas.txt",etiquetas,duracion,n_etiquetas);
    //Armar arreglos con Reproducciones.txt
    double tarifa=0.78;
    int duracionTotalEtiqueta[MAX_ETIQUETAS]{};
    int reproTotalPorEtiqueta[MAX_ETIQUETAS]{};
    double ingresosDuracionEtiquetas[MAX_ETIQUETAS]{};
    int reproTotalCanal[MAX_CANALES]{};
    ArmarArreglos("Datos/Reproducciones.txt",etiquetas,duracionTotalEtiqueta,n_etiquetas,
                   c_canal,int_canal,duracion,n_canales,
                   reproTotalPorEtiqueta,reproTotalCanal,tarifa,
                   ingresosDuracionEtiquetas);
    imprimir_reporte("Reportes/Reporte.txt",etiquetas,duracionTotalEtiqueta,n_etiquetas,
                    c_canal,int_canal,duracion,n_canales,rating_canal,reproTotalPorEtiqueta,
                    reproTotalCanal,fechaCreacion,tarifa,ingresosDuracionEtiquetas);
    return 0;
}