//
// Created by Madi on 8/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_leer_info();
}

void imprimir_encabezado() {
    cout<<setw(40)<<""<<"EMPRESA DE SALUD S.A."<<endl;
    imprimir_linea(120,'=');
    cout<<setw(30)<<""<<"REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS"<<endl;
    imprimir_linea(120,'=');

}

void imprimir_linea(int n, char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void estatico() {
    cout<<"Fecha";
    cout<<setw(6)<<""<<"Paciente";
    cout<<setw(6)<<""<<"Inicio";
    cout<<setw(6)<<""<<"Fin";
    cout<<setw(6)<<""<<"Duracion (H:M:S)";
    cout<<setw(6)<<""<<"Duracion (H)";
    cout<<setw(6)<<""<<"Especialidad";
    cout<<setw(6)<<""<<"Pago (cita+medicinas)"<<endl;
    imprimir_linea(120,'-');
}

void imprimir_leer_info() {
    int compararfecha=2024115,fecha,CardioYFecha=0,dd,mm,yyyy;
    double cantPacientes=0,cantS=0,cantDerma=0,CantNYgasto=0,cantPediatra=0,gasto,cantN=0;
    double horasI,horasF,duracion,tarifa,gastoMedicina=0,gastoMedicinaTotal=0,gastoTotal=0,gastoMedicinaTotalDerma=0;
    double PromS,PromDerma,PorcentajeN,porcentajeP,PorcentajeNYgasto;
    char c,car,receta;
    estatico();
    while (true) {
        almacenar_y_leer_fecha(fecha,dd,mm,yyyy);
        if (cin.eof()) break;
        cout<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<setfill('0')<<mm<<'/'<<yyyy;
        cout<<setfill(' ');
        while (true) {
            leerDNI();
            leer_y_calcularHora(horasI);
            leer_y_calcularHora(horasF);
            duracion=horasF-horasI;
            imprimirDuracion(duracion);
            cout<<setw(6)<<""<<duracion;
            cin>>tarifa;
            leerEImprimirEspecialidad(car);
            if (fecha>compararfecha and car=='C') CardioYFecha++;
            if (car=='P') cantPediatra++;
            cin>>ws;
            cin.get(receta);
            if (receta=='S') {
                cantS++;
                cin>>gastoMedicina;
                gastoMedicinaTotal=gastoMedicinaTotal+gastoMedicina;
                if (car=='D') {
                    cantDerma++;
                    gastoMedicinaTotalDerma=gastoMedicinaTotalDerma+gastoMedicina;
                }
            }
            gasto=gastoMedicina+duracion*tarifa;
            gastoTotal=gastoTotal+gasto;
            if (receta=='N') {
                cantN++;
                if (gasto>350.0) CantNYgasto++;
            }
            cout<<setw(6)<<""<<gasto<<endl;
            cantPacientes++;
            cin.get(c);
            if (c=='\n') break;
        }
    }
    PromS=gastoMedicinaTotal/cantS;
    PromDerma=gastoMedicinaTotal/cantDerma;
    PorcentajeN=(cantN/cantPacientes)*100;
    porcentajeP=(cantPediatra/cantPacientes)*100;
    PorcentajeNYgasto=(CantNYgasto/cantPacientes)*100;
    imprimir_estadisticas(PromS,PromDerma,PorcentajeN,porcentajeP,CardioYFecha,PorcentajeNYgasto);
}

void imprimir_estadisticas(double PromS,double PromDerma,double porcentajeN,double porcentajePediatra,int PacCardio,double PorcenNYGasto) {
    imprimir_linea(120,'=');
    cout<<setw(4)<<""<<"ESTADISTICAS OBTENIDAS"<<endl;
    cout<<setw(4)<<""<<"Promedio de gastos por medicina de los pacientes que le recetaron medicinas "<<PromS<<endl;
    cout<<setw(4)<<""<<"Promedio de gastos por medicina de los pacientes que se atendieron en dermatologia "<<PromDerma<<endl;
    cout<<setw(4)<<""<<"Porcentaje de pacientes que no le recetaron medicinas "<<porcentajeN<<endl;
    cout<<setw(4)<<""<<"Porcentaje de pacientes que se atendieron en pediatria "<<porcentajePediatra<<endl;
    cout<<setw(4)<<""<<"Cantidad de pacientes que se atendieron en cardiologia despues del 15/01/2024 "<<PacCardio<<endl;
    cout<<setw(4)<<""<<"Porcentaje de pacientes que no le recetaron medicinas y que gasto mas de 350.00 "<<PorcenNYGasto<<endl;
    imprimir_linea(120,'=');
}

void imprimir_gastos(double gastos) {
    imprimir_linea(120,'=');
    cout<<"Total de ingresos : "<<gastos<<endl;
}

void almacenar_y_leer_fecha(int &fecha,int &dd,int &mm,int &yyyy) {
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    fecha=yyyy*1000+mm*100+dd;
}
void leerDNI() {
    int DNI;
    cin>>DNI;
    cout<<setw(2)<<""<<DNI;
}

void leer_y_calcularHora(double &horas) {
    double h,m,s;
    char c;
    cin>>h>>c>>m>>c>>s;
    cout<<setw(2)<<""<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
    horas=(h+m/60+s/3600);
}

void imprimirDuracion (double duracion) {
    int h,m,s;
    double m1,s1;
    h=duracion;
    m1=(duracion-h)*60;
    m=m1;
    s1=(m1-m)*60;
    s=s1;
    cout<<setw(2)<<""<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
}

void leerEImprimirEspecialidad(char &c) {
    cin>>ws;
    cin.get(c);
    if (c=='C') {
        cout<<setw(5)<<""<<"Cardiologia";
    }
    else if (c=='D') {
        cout<<setw(5)<<""<<"Dermatologia";
    }
    else if (c=='P') {
        cout<<setw(5)<<""<<"Pediatria";
    }
}


