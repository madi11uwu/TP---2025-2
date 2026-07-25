#include "Bibliotecas/Funciones.hpp"

int main() {
    //Canales.txt
    int FechaCreacion[MAX_CANALES]{};
    char c_canal[MAX_CANALES]{};
    int int_canal[MAX_CANALES]{};
    double rating[MAX_CANALES]{};
    int n_canales=0;
    cargarCanales("ArchivosDeDatos/Canales.txt",FechaCreacion,
                    c_canal,int_canal,rating,n_canales);
    probarCanales("ArchivosDeReporte/reporte_prueba_canales.txt",FechaCreacion,
                    c_canal,int_canal,rating,n_canales);
    //Etiquetas.txt
    int codigo_etiqueta[MAX_ETIQUETAS]{};
    int duracion[MAX_ETIQUETAS]{};
    int n_etiquetas=0;
    cargarEtiquetas("ArchivosDeDatos/Etiquetas.txt",codigo_etiqueta,duracion,n_etiquetas);
    probarEtiquetas("ArchivosDeReporte/reporte_prueba_etiquetas.txt",codigo_etiqueta,duracion,n_etiquetas);
    ordenarEtiquetas(codigo_etiqueta,duracion,n_etiquetas);
    //EtiquetasEnCanales.txt
    char char_canal[MAX_ETIQUETASENCANALES]{};
    int codigo_canal[MAX_ETIQUETASENCANALES]{};
    int etiqueta[MAX_ETIQUETASENCANALES]{};
    int n_etiquetasEnCanales=0;
    cargarEtiquetasEnCanales("ArchivosDeDatos/EtiquetasEnCanales.txt",char_canal,codigo_canal,
                            etiqueta,n_etiquetasEnCanales);
    probarEtiquetasEnCanales("ArchivosDeReporte/reporte_etiquetasEnCanales.txt",char_canal,
                                codigo_canal,etiqueta,n_etiquetasEnCanales);
    //Generar arreglos con ReproduccionesDeEtiquetas.txt
    int NumeroTotalRepros[MAX_ETIQUETASENCANALES]{};
    int DuracionTotalRepros[MAX_ETIQUETASENCANALES]{};
    double tarifa;
    //cin>>tarifa;
    tarifa=0.78;
    GenerarArreglos("ArchivosDeDatos/ReproduccionesDeEtiquetas.txt",
                    codigo_etiqueta,duracion,
                    n_etiquetas,char_canal,codigo_canal,
                    etiqueta,n_etiquetasEnCanales,
                    NumeroTotalRepros,DuracionTotalRepros);
    imprimir_reporte("ArchivosDeReporte/ReporteDeCanales_Y_Etiquetas.txt",c_canal,
                        int_canal,rating,
                        n_canales,codigo_etiqueta,
                        duracion,n_etiquetas,tarifa,
                        NumeroTotalRepros,DuracionTotalRepros,
                        char_canal,codigo_canal,
                        etiqueta,n_etiquetasEnCanales);
    return 0;
}