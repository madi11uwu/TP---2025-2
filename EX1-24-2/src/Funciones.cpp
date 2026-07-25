//
// Created by Madi on 11/10/2025.
//

#include "Funciones.hpp"

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void generarReporte(const char *clientes, const char *platos,const char *repartidores,
                    const char *repartos, const char *reporte) {
    ifstream leer_clientes;
    ifstream leer_platos;
    ifstream leer_repartidos;
    ifstream leer_repartos;
    ofstream write;
    apertura_lectura(clientes,leer_clientes);
    apertura_lectura(platos,leer_platos);
    apertura_lectura(repartidores,leer_repartidos);
    apertura_lectura(repartos,leer_repartos);
    apertura_escritura(reporte,write);
    imprimir_reporte(leer_clientes,leer_platos,leer_repartidos,
                        leer_repartos,write);
    leer_clientes.close();
    leer_platos.close();
    leer_repartidos.close();
    leer_repartos.close();
    write.close();
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"CLIENTES POR ATENDER"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void leer_nombres(ifstream &leer, ofstream &write, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
        if (car=='_') car=' ';
        write.put(car);
    }
}

void imprimirDatosEstaticos(ifstream &leer_clientes, ofstream &write,int DNI,int &codigo_distrito,
                            double &descuento,char c_vehiculo) {
    char desc,c;
    write<<"CLIENTES: "<<DNI<<" - ";
    leer_nombres(leer_clientes,write,']');
    leer_clientes>>codigo_distrito;
    write<<" DISTRITO: ";
    leer_nombres(leer_clientes,write,' ');
    leer_clientes>>ws>>c_vehiculo;
    write<<" TIPO DE VEHICULO: ";
    escribir_vehiculo(write,c_vehiculo);
    leer_clientes>>ws>>desc;
    if (desc=='S') {
        leer_clientes>>descuento>>c;
    }
    else if (desc=='N')descuento=0.0;
    write<<" DESCUENTO: "<<fixed<<setprecision(2)<<descuento<<"%"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void escribir_vehiculo(ofstream &write,char c) {
    if (c=='M')write<<"Motocicleta";
    else if (c=='B')write<<"Bicicleta";
}
void imprimir_reporte(ifstream &leer_clientes,ifstream &leer_platos,
                        ifstream &leer_repartidos,ifstream &leer_repartos,ofstream &write) {
    int DNI,codigo_distrito;
    double subTotalCliente,descuentoClienteTotal,descuento;
    char c_vehiculo;
    imprimirEncabezado(write);
    while (true) {
        leer_clientes>>DNI;
        if (leer_clientes.eof())break;
        imprimirDatosEstaticos(leer_clientes,write,DNI,codigo_distrito,descuento,c_vehiculo);
        write<<"REPARTOS: "<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        int nro_pedido=1;
        imprimir_datosDinamicos(nro_pedido,write,DNI,leer_repartos,leer_platos,
                                subTotalCliente,descuentoClienteTotal,descuento,c_vehiculo);
        imprimir_linea(ANCHO_REPORTE,'-',write);
    }
}

void imprimir_datosDinamicos(int &nro_pedido,ofstream &write,int DNI,ifstream &leer_repartos,
                            ifstream &leer_platos,double descuento,char c_vehiculo,double &PagoClienteTotal,
                                double &pagoRepartidorTotal) {
    leer_repartos.clear();
    leer_repartos.seekg(0,ios::beg);
    int numero_pedido,DNILeido,cantidad,codigo_plato;
    char c;
    double subtotal,plato_descuento,pagoRepartidor,subTotalCliente=0.0,descuentoClienteTotal=0.0,TotalPagagoCliente;
    pagoRepartidorTotal=0.0,PagoClienteTotal=0.0;
    while (true) {
        leer_repartos>>numero_pedido;
        if (leer_repartos.eof())break;
        leer_repartos>>DNILeido;
        if (DNILeido==DNI) {
            write<<setw(2)<<setfill('0')<<nro_pedido<<")";
            write<<setfill(' ');
            write<<" PEDIDO: "<<numero_pedido<<endl;
            imprimir_encabezadoPedido(write);
            int nro_plato=1;
            while (true) {
                leer_repartos>>cantidad>>codigo_plato;
                imprimir_Dinamico(leer_platos,cantidad,codigo_plato,write,
                                    nro_plato,subtotal,plato_descuento);
                subTotalCliente+=subtotal,descuentoClienteTotal+=plato_descuento;
                nro_plato++;
                c=leer_repartos.get();
                if (c=='\n')break;
            }
            imprimirEstadisticasPedido(subTotalCliente,descuentoClienteTotal,descuento,c_vehiculo,
                write,TotalPagagoCliente,pagoRepartidor);
            pagoRepartidorTotal+=pagoRepartidor,PagoClienteTotal+=TotalPagagoCliente;
            nro_pedido++;
        }
        else {
            leer_repartos.ignore (1000,'\n');
            continue;
        }
    }
}

void imprimirEstadisticasPedido(double subTotalCliente,double descuentoClienteTotal,
                                double descuento,char c_vehiculo,ofstream &write,
                                double &TotalPagagoCliente,double &pagoRepartidor) {
    write<<setw(5)<<"TOTAL PEDIDO SIN DESCUENTOS: "<<subTotalCliente<<endl;
    write<<setw(5)<<"DESCUENTO TOTAL POR PLATOS: "<<descuentoClienteTotal<<endl;
    write<<setw(5)<<"DESCUENTO DEL CLIENTE: "<<descuento<<endl;
    TotalPagagoCliente=(subTotalCliente-descuentoClienteTotal)*(100-descuento)/100.0;
    write<<setw(5)<<"TOTAL PAGADO POR EL CLIENTE: "<<TotalPagagoCliente<<endl;
    pagoRepartidor=TotalPagagoCliente*DevolverPorcentajeRepartidor(c_vehiculo)/100.0;
    write<<setw(5)<<"PAGO AL REPARTIDOR: "<<pagoRepartidor<<endl;
}

int DevolverPorcentajeRepartidor(char c) {
    if (c=='M')return 10;
    else if (c=='B')return 5;
}
void imprimir_encabezadoPedido(ofstream &write) {
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"PLATO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CANTIDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"PRECIO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"SUBTOTAL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DESCUENTO"<<endl;
}

void imprimir_Dinamico(ifstream &leer_platos,int cantidad,
                        int codigo_plato,ofstream &write,int nro_plato,double &subtotal,
                        double &plato_descuento) {
    double precio,descuento;
    write<<setw(5)<<""<<nro_plato<<")";
    write<<codigo_plato<<"-";
    imprimirPlatoyBuscarPrecio(codigo_plato,leer_platos,write,precio,descuento);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<cantidad;
    subtotal=precio*cantidad;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<precio;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<subtotal;
    plato_descuento=subtotal*descuento/100.0;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<descuento<<"%"<<" - ";
    write<<plato_descuento<<endl;
}

void imprimirPlatoyBuscarPrecio(int codigo_plato,ifstream &leer_platos,ofstream &write,
                                double &precio,double &descuento) {
    leer_platos.clear();
    leer_platos.seekg(0,ios::beg);
    int codigo_leido,cantidad;
    char c;
    while (true) {
        leer_platos>>codigo_leido;
        if (leer_platos.eof())break;
        if (codigo_leido==codigo_plato) {
            leer_nombres(leer_platos,write,'}');
            leer_platos>>precio>>cantidad;
            c=leer_platos.get();
            if (c=='\n')descuento=0.0;
            else {
                leer_platos>>descuento>>c;
            }
        }
        else {
            leer_platos.ignore (1000,'\n');
            continue;
        }
    }
}