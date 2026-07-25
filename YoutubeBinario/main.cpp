#include "src/Funciones.hpp"

int main() {
    //Videos.txt
    int codigo_video[MAX_VIDEOS]{};
    int duracion_video[MAX_VIDEOS]{};
    int codigo_idioma[MAX_VIDEOS]{};
    char char_categoria[MAX_VIDEOS]{};
    int int_categoria[MAX_VIDEOS]{};
    int n_videos = 0;
    cargar_ordenado_videos("Datos/Videos.txt", codigo_video, duracion_video,
                           codigo_idioma, char_categoria, int_categoria, n_videos);
    probar_videos("Reportes/Reporte1.txt",codigo_video,duracion_video,codigo_idioma,
                            char_categoria,int_categoria,
                            n_videos);
    //Canales.txt
    int ReproAntigua[MAX_VIDEOS]{};
    int ReproReciente[MAX_VIDEOS]{};
    int cantVideo[MAX_VIDEOS]{};
    double sumaRating[MAX_VIDEOS]{};
    double sumaTasa[MAX_VIDEOS]{};
    llenarArreglos("Datos/CanalesYoutube.txt", codigo_video,
                   n_videos,ReproAntigua,ReproReciente,cantVideo,
                    sumaRating, sumaTasa);
    imprimir_reporte("Reportes/Reporte.txt", codigo_video, duracion_video,
                     codigo_idioma, char_categoria, int_categoria,
                     n_videos, ReproAntigua, ReproReciente, cantVideo,
                     sumaRating, sumaTasa);
    return 0;
}
