#include "src/Funciones.hpp"
#include "src/UsuarioConElLibro.hpp"
#include "src/LibroEnSuPoder.hpp"
#include "src/Libro.hpp"
#include "src/Usuario.hpp"

int main() {
    //libros.csv
    struct Libro *libros;
    int n_libros=0;
    cargarLibros("Datos/Libros.csv",libros,n_libros);
    probarLibros("Reportes/InicialLibros.txt",libros,n_libros);
    //usuarios.csv
    struct Usuario *usuarios;
    int n_usuarios=0;
    cargarUsuarios("Datos/Usuarios.csv",usuarios,n_usuarios);
    probarUsuarios("Reportes/InicialUsuarios.txt",usuarios,n_usuarios);
    //PrestamoDeLibros.txt
    CompletarPrestamos("Datos/PrestamoDeLibros.txt",usuarios,libros,n_usuarios,n_libros);
    probarLibros("Reportes/LibrosConPrestamos.txt",libros,n_libros);
    probarUsuarios("Reportes/UsuariosConPrestamos.txt",usuarios,n_usuarios);
    ordenarLibro(libros,n_libros);
    probarLibros("Reportes/LibrosOrdenado.txt",libros,n_libros);
    return 0;
}
