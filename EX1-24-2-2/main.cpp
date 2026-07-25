#include "src/Funciones.hpp"

int main() {
    //Clientes.txt
    int DNICliente[MAX_CLIENTES]{};
    int codigo_distrito[MAX_CLIENTES]{};
    char tipo_vehiculo[MAX_CLIENTES]{};
    double descuento[MAX_CLIENTES]{};
    int n_clientes=0;
    cargarClientes("Datos/Clientes.txt",DNICliente,codigo_distrito,tipo_vehiculo,
                    descuento,n_clientes);
    probarClientes("Reportes/reporte_prueba_clientes.txt",DNICliente,codigo_distrito,tipo_vehiculo,
                   descuento,n_clientes);
    //PlatosOfrecidos.txt
    int codigo_plato[MAX_PLATOS]{};
    double precioPlato[MAX_PLATOS]{};
    int cantidadHecha[MAX_PLATOS]{};
    double descuentoPlato[MAX_PLATOS]{};
    int n_platos=0;
    cargarPlatos("Datos/PlatosOfrecidos.txt",codigo_plato,precioPlato,cantidadHecha,
                    descuentoPlato,n_platos);
    probarPlatos("Reportes/reporte_prueba_platos.txt",codigo_plato,precioPlato,cantidadHecha,
                    descuentoPlato,n_platos);
    return 0;
}