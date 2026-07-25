#include "src/Funciones.hpp"

int main() {
    //Clientes.txt
    int DNICliente[MAX_CLIENTES]{};
    int codigo_distrito[MAX_CLIENTES]{};
    char c_vehiculo[MAX_CLIENTES]{};
    double descuento[MAX_CLIENTES]{};
    int n_clientes = 0;
    cargarClientes("Datos/Clientes.txt",DNICliente,codigo_distrito,c_vehiculo,
                    descuento,n_clientes);
    probarClientes("Reportes/reporte_prueba_clientes.txt",DNICliente,codigo_distrito,c_vehiculo,
                    descuento,n_clientes);
    //PlatosOfrecidos.txt
    int codigo_plato[MAX_PLATOS]{};
    double precio_plato[MAX_PLATOS]{};
    int cantidadHecha[MAX_PLATOS]{};
    double descuento_plato[MAX_PLATOS]{};
    int n_platos = 0;
    cargarPlatos("Datos/PlatosOfrecidos.txt",codigo_plato,precio_plato,cantidadHecha,
                descuento_plato,n_platos);
    probarPlatos("Reportes/reporte_prueba_platos.txt",codigo_plato,precio_plato,cantidadHecha,
                descuento_plato,n_platos);
    //RepartosARealizar.txt
    int cantidadAtentida[MAX_PLATOS]{};
    int cantidadNoAtendida[MAX_PLATOS]{};
    double MontoEsperado[MAX_PLATOS]{};
    double montoBruto[MAX_PLATOS]{};
    double montoRecibido[MAX_PLATOS]{};
    GenerarArreglos("Datos/RepartosARealizar.txt",DNICliente,descuento,
                    n_clientes,codigo_plato,precio_plato,cantidadHecha,descuento_plato,
                    n_platos,cantidadAtentida,cantidadNoAtendida,MontoEsperado,
                    montoBruto,montoRecibido);
    ordenarArreglos(codigo_plato,precio_plato,cantidadHecha,descuento_plato,
                    n_platos,cantidadAtentida,cantidadNoAtendida,MontoEsperado,
                    montoBruto,montoRecibido);
    imprimirReporte("Reportes/ReporteDeRelacionDePlatos.txt",codigo_plato,precio_plato,
                    cantidadHecha,descuento_plato,
                    n_platos,cantidadAtentida,cantidadNoAtendida,MontoEsperado,
                    montoBruto,montoRecibido);
    LimpiarArreglos(codigo_plato,precio_plato,cantidadHecha,descuento_plato,
                    n_platos,cantidadAtentida,cantidadNoAtendida,MontoEsperado,
                    montoBruto,montoRecibido);
    return 0;
}