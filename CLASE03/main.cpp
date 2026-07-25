#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout << right << setw(10) << "Hello" << endl;
    cout << left << setw(10) << "World" << endl;
    cout << right << setw(10) << "Madison Obregon Cruz"; //ignora cualquier tipo de alineación para
                                                            //imprimir lo que se solicita aunque no alcance el espacio
    cout << right << setfill('*'); //va antes de una línea de código de un setw para rellenar el vacío
    cout << right << setw(10) << 18 << endl;
    cout << fixed << setprecision(2) << 3.14159;
    return 0;
}