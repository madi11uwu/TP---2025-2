#include "src/Funciones.hpp"

int main() {
    //lexicon.csv
    struct Palabra lexicon[100]{};
    int n_lexicon = 0;
    cargarPalabra("Datos/lexicon.csv",lexicon,n_lexicon);
    //platos.csv
    struct Plato *platos;
    int n_platos = 0;
    cargarPlato("Datos/platos.csv",platos,n_platos);
    //atenciones.txt
    struct Atencion atenciones[100]{};
    int n_atencion=0;
    cargarAtencion("Datos/atenciones.txt", atenciones, n_atencion, platos,
                   n_platos);
    //comentarios.csv
    CompletarAtencion("Datos/comentarios.csv",atenciones,lexicon,n_atencion,n_lexicon);
    imprimirReporte("Reportes/ReporteAtencionesAnalisisSentimiento.txt",atenciones,n_atencion);
    return 0;
}
