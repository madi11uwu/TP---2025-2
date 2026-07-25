#include "src/Funciones.hpp"
//CanalesYoutube.txt
//parte estática: fecha creación, nombreCanal
//parte dinámica: codigo video subido, fecha publicación, hora publicacion, rating, tasa de abandono
//Videos.txt
//codigo video, duracion, codigo idioma, categoria
//REPORTE:
//stream, idioma, rep antigua, rep reciente, prom. rat. cal. drop off, durac.
int main() {
    //Videos.txt
    int codigoVideos[MAX_VIDEOS]{};
    int duracion[MAX_VIDEOS]{};
    int codigoIdioma[MAX_VIDEOS]{};
    int n_videos=0;
    cargarVideos("Datos/Videos.txt",codigoVideos,duracion,
                    codigoIdioma,n_videos);
    probarVideos("Reporte/reporte_prueba_videos",codigoVideos,duracion,
                    codigoIdioma,n_videos);
    //CanalesYoutube.txt
    int RepAntigua[MAX_VIDEOS]{};
    int RepReciente[MAX_VIDEOS]{};
    double promedioRating[MAX_VIDEOS]{};
    double promedioTasaAbandono[MAX_VIDEOS]{};
    GenerarArreglos("Datos/CanalesYoutube.txt",RepAntigua,RepReciente,promedioRating,
                    promedioTasaAbandono,codigoVideos);


    return 0;
}