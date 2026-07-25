#include "src/Funciones.hpp"
#include "src/LibroEnSuPoder.hpp"
#include "src/Usuario.hpp"
#include "src/NodoUsuario.hpp"
#include "src/NodoUsuarioMoroso.hpp"

int main() {
    //usuarios.csv
    struct NodoUsuario *listaUsuario;
    cargarUsuarios("Datos/Usuarios.csv",listaUsuario);
    probarUsuarios("Reportes/UsuariosInicial.txt",listaUsuario,"LISTA DE USUARIOS INICIAL");
    //PrestamoDeLibros.txt
    ActualizarLista("Datos/PrestamoDeLibros.txt",listaUsuario);
    probarUsuarios("Reportes/UsuariosConPrestamosAEntregar.txt",listaUsuario,"LISTA DE USUARIOS CON PRESTAMOS A ENTREGAR");
    //usuariosMorosos.txt
    struct NodoUsuarioMoroso *listaUsuarioMoroso;
    cargarMorosos("Datos/usuariosMorosos.txt",listaUsuarioMoroso);
    probarMorosos("Reportes/ReporteUsuariosMorosos.txt",listaUsuarioMoroso);
    //Eliminar
    struct NodoUsuario *listoMoroso;
    EliminarMorosos(listaUsuario,listaUsuarioMoroso,listoMoroso);
    probarUsuarios("Reportes/UsuariosConPrestamosCorrectos.txt",listaUsuario,"LISTA DE USUARIOS CON PRESTAMOS CON PRESTAMOS CORRECTOS");
    probarUsuarios("Reportes/UsuariosConPrestamosBloqueados.txt",listoMoroso,"LISTA DE USUARIOS CON PRESTAMOS BLOQUEADOS");
    return 0;
}
