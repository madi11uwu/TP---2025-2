#include "src/Funciones.hpp"

int main() {
    //Videos.txt
    int codigo_video[MAX_VIDEOS]{};
    int duracion[MAX_VIDEOS]{};
    int codigo_idioma[MAX_VIDEOS]{};
    int n_videos = 0;
    cargarVideos("Datos/Videos.txt",codigo_video,
                    duracion,codigo_idioma,n_videos);
    probarVideos("Reportes/reporte_prueba_videos.txt",codigo_video,
                duracion,codigo_idioma,n_videos);
    //CanalesYoutube.txt
    int UltimaFecha[MAX_VIDEOS]{};
    int FechaAntigua[MAX_VIDEOS]{};
    int veces[MAX_VIDEOS]{};
    double sumaRating[MAX_VIDEOS]{};
    double sumatasas[MAX_VIDEOS]{};
    GenerarArreglos("Datos/CanalesYoutube.txt",codigo_video,
                    n_videos,UltimaFecha,
                    FechaAntigua,veces,sumaRating,
                    sumatasas);
    imprimirReporte("Reportes/ReporteSinOrdenar.txt",codigo_video,duracion,
                    codigo_idioma,n_videos,UltimaFecha,FechaAntigua,veces,
                    sumaRating,sumatasas);
    ordenarArreglos(codigo_video,duracion,codigo_idioma,n_videos,UltimaFecha,
        FechaAntigua,veces,sumaRating,sumatasas);
    imprimirReporte("Reportes/ReporteOrdenado.txt",codigo_video,duracion,
                    codigo_idioma,n_videos,UltimaFecha,FechaAntigua,veces,
                    sumaRating,sumatasas);
    return 0;
}