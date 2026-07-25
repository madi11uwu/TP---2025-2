#include "src/Funciones.hpp"
#include "src/Cliente.hpp"
#include "src/Plato.hpp"
#include "src/Distrito.hpp"
#include "src/PlatoPedido.hpp"
#include "src/Cliente.hpp"

int main() {
    struct Distrito distrito[MAX_DISTRITOS]{};
    struct Plato plato[MAX_PLATOS]{};
    struct Cliente cliente[MAX_CLIENTES]{};
    int n_distrito = 0;
    int n_plato = 0;
    int n_clientes = 0;
    cargar_distrito("Datos/lab8_Distritos.csv",distrito,n_distrito);
    cargar_platos("Datos/lab8_PlatosOfrecidos.csv",plato,n_plato);
    cargar_cliente("Datos/lab8_Clientes.csv",cliente,n_clientes);
    probar_distrito("Reportes/reporteDistrito.txt",distrito,n_distrito);
    probar_platos("Reportes/reportePlatos.txt",plato,n_plato);
    probar_cliente("Reportes/reporteCliente.txt",cliente,n_clientes);
    //Llenar Cliente
    llenarArregloCliente("Datos/lab8_PedidosRealizados.txt", distrito, plato,
                         cliente, n_distrito, n_clientes, n_plato);
    ordenarCliente(cliente,n_clientes);
    ordenarPlatosPedidos(cliente,n_clientes);

    return 0;
}
