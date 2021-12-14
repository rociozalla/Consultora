cmake_minimum_required(VERSION 3.19)
project(Consultora)

set(CMAKE_CXX_STANDARD 11)

add_executable(consultora main.cpp estructuras/lista.cpp estructuras/lista.h dominio/empresa.cpp dominio/empresa.h servicios/gestorempresa.cpp servicios/gestorempresa.h estructuras/arbol.cpp estructuras/arbol.h utilidades/lectorempresas.cpp utilidades/lectorempresas.h estructuras/arbolprioridad.cpp estructuras/arbolprioridad.h)