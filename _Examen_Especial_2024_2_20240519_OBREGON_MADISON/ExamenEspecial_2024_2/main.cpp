#include "src/Funciones.hpp"
#include "src/Palabra.hpp"
#include "src/NodoLexicon.hpp"
#include "src/Comentario.hpp"
#include "src/Plato.hpp"
#include "src/Atencion.hpp"
#include "src/NodoPlato.hpp"

int main() {
    //lexicon.csv
    struct NodoLexicon *listaLexicon;
    cargarLexicon("Datos/lexicon.csv",listaLexicon);
    probarLexicon("Reportes/PruebaDeLexicon.txt",listaLexicon,"PRUEBA DE LEXICON");
    //platos.csv
    struct NodoPlato *listaPlato;
    cargarPlatos("Datos/platos.csv",listaPlato);
    probarPlatos("Reportes/PruebaDePlatos.txt",listaPlato,"PRUEBA DE PLATOS");
    //atenciones.txt
    struct NodoAtencion *listaAtencion;
    cargarAtencion("Datos/atenciones.txt",listaAtencion,listaPlato);
    //comentarios.csv
    CompletarAtencion("Datos/comentarios.csv",listaAtencion,listaLexicon);
    imprimirReporte("Reportes/ReporteAtencionesAnalisisSentimiento.txt",listaAtencion);
    return 0;
}
