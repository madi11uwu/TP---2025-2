#include "src/Funciones.hpp"

int main() {
    //Canales.txt
    int fechaCreacion[MAX_CANALES]{};
    char cCanal[MAX_CANALES]{};
    int int_canal[MAX_CANALES]{};
    double rating[MAX_CANALES]{};
    int n_canal = 0;
    cargarCanales("Datos/Canales.txt",fechaCreacion,cCanal,int_canal,rating,n_canal);
    probarCanales("Reportes/reporte_prueba_canales",fechaCreacion,cCanal,int_canal,rating,n_canal);
    //Etiquetas.txt
    int codigoEtiqueta[MAX_ETIQUETAS]{};
    int duracionEtiqueta[MAX_ETIQUETAS]{};
    int n_etiquetas = 0;
    cargarEtiquetas("Datos/Etiquetas.txt",codigoEtiqueta,duracionEtiqueta,n_etiquetas);
    probarEtiquetas("Reportes/reporte_prueba_etiquetas",codigoEtiqueta,duracionEtiqueta,n_etiquetas);
    //Armas arreglos con Reproducciones.txt
    int TotalReproEtiqueta[MAX_ETIQUETAS]{};
    int TotalTiempoReproEtiqueta[MAX_ETIQUETAS]{};
    int TotalReproCanal[MAX_CANALES]{};
    int TotalTiempoReproCanal[MAX_CANALES]{};
    double tarifa=0.78;
    ArmarEtiquetas("Datos/Reproducciones.txt",codigoEtiqueta,duracionEtiqueta,n_etiquetas,
                        cCanal,int_canal,n_canal,TotalReproEtiqueta,TotalTiempoReproEtiqueta,
                        TotalReproCanal,TotalTiempoReproCanal);
    imprimir_reporte("Reportes/Reporte",codigoEtiqueta,duracionEtiqueta,n_etiquetas,
                        fechaCreacion,cCanal,int_canal,rating,n_canal,
                        TotalReproEtiqueta,TotalTiempoReproEtiqueta,TotalReproCanal,
                        TotalTiempoReproCanal,tarifa);
    return 0;
}