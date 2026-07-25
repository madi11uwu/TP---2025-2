#include <iostream>

using namespace std;

#define  MAX_CANALES 120
#define  MAX_ETIQUETAS 120
#define  MAX_ETIQ_CANAL 600
#include "src/Funciones.hpp"

int main() {
    char arrCarCodCanal[MAX_CANALES]{};
    int arrNumCodCanal[MAX_CANALES]{}, cantCanales = 0;
    double arrRatingCanal[MAX_CANALES]{};

    llenarArrCanales("Archivos De Datos/Canales (1).txt",
                     arrCarCodCanal, arrNumCodCanal, arrRatingCanal, cantCanales);


    int arrCodEtiquetas[MAX_ETIQUETAS]{}, cantEtiquetas = 0,
            arrDuracionEtiquetas[MAX_ETIQUETAS]{};

    llenarArrEtiquetas("Archivos De Datos/Etiquetas (1).txt",
                       arrCodEtiquetas, arrDuracionEtiquetas, cantEtiquetas);


    char arrCarCodEtiquetaxCanal[MAX_ETIQ_CANAL]{};
    int arrNumCodEtiquetaxCanal[MAX_ETIQ_CANAL]{},
            arrCodEtiquetaxCanal[MAX_ETIQ_CANAL]{},
            cantEtiquetasXCanal = 0;

    llenarArrEtiquetasXCanal("Archivos De Datos/EtiquetasEnCanales.txt",
                             arrCarCodEtiquetaxCanal,
                             arrNumCodEtiquetaxCanal, arrCodEtiquetaxCanal,
                             cantEtiquetasXCanal);

    int arrNumeroTotalReproducciones[MAX_ETIQ_CANAL]{},
            arrTotalDuracion[MAX_ETIQ_CANAL]{};

    llenarArrAuxiliareas("Archivos De Datos/ReproduccionesDeEtiquetas (1).txt",
                         arrCarCodEtiquetaxCanal,
                         arrNumCodEtiquetaxCanal, arrCodEtiquetaxCanal,
                         cantEtiquetasXCanal,
                         arrNumeroTotalReproducciones, arrTotalDuracion,
                         arrCodEtiquetas, arrDuracionEtiquetas, cantEtiquetas);

    elaborarReporte("Archivos De Reportes/Reporte.txt",
                    arrCarCodCanal, arrNumCodCanal, arrRatingCanal, cantCanales,
                    arrCodEtiquetas, arrDuracionEtiquetas, cantEtiquetas,
                    arrCarCodEtiquetaxCanal,
                    arrNumCodEtiquetaxCanal, arrCodEtiquetaxCanal,
                    cantEtiquetasXCanal,

                    arrNumeroTotalReproducciones, arrTotalDuracion);


    return 0;
}
