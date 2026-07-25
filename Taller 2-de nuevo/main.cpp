#include "src/Funciones.hpp"

int main() {
    //Usuarios.csv
    struct NodoUsuario *listaUsuario;
    cargarUsuarios("Datos/Usuarios.csv",listaUsuario);
    probarUsuarios("Reportes/UsuariosInicial.txt",listaUsuario,"LISTA DE USUARIOS INICIAL");
    //PrestamosDeLibros.txt
    ActualizarUsuarios("Datos/PrestamoDeLibros.txt",listaUsuario);
    probarUsuarios("Reportes/UsuariosConPrestamosAEntregar.txt",listaUsuario,"LISTA DE USUARIOS CON PRESTAMOS A ENTREGAR");
    //usuariosMorosos.txt
    struct NodoUsuarioMoroso *ListaMoroso;
    cargarMorosos("Datos/usuariosMorosos.txt",ListaMoroso);
    probarMorosos("Reportes/ReporteUsuariosMorosos.txt",ListaMoroso);
    struct NodoUsuario *listaOrdenada;
    eliminarNodos(listaUsuario,ListaMoroso,listaOrdenada);
    probarUsuarios("Reportes/UsuariosConPrestamosCorrectos.txt",listaUsuario,"USUARIOS CON PRESTAMOS CORRECTOS");
    probarUsuarios("Reportes/UsuariosConPrestamosBloqueados.txt",listaOrdenada,"LISTA DE USUARIOS CON PRESTAMOS BLOQUEADOS");
    return 0;
}
