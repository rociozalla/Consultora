#ifndef CONSULTORA_ARBOLPRIORIDAD_H
#define CONSULTORA_ARBOLPRIORIDAD_H

#include "../dominio/empresa.h"
#include "../estructuras/lista.h"

struct NodoArbolPrioridad {

    NodoArbolPrioridad(Empresa * empresa, int mediana, NodoArbolPrioridad * izq, NodoArbolPrioridad * der):
            empresa(empresa),
            mediana(mediana),
            izq(izq),
            der(der) {}

    Empresa * empresa;
    int mediana;
    NodoArbolPrioridad * izq;
    NodoArbolPrioridad * der;
};

class ArbolPrioridad {
private:
    NodoArbolPrioridad * raiz;

    int _calcularMediana(Empresa * empresas[], int cantidadEmpresas);
    void _ordernarEmpresasPorCantidadEmpleados(Empresa * empresas[], int cantidadEmpresas, Empresa * ordenado[]);
    NodoArbolPrioridad * _construirArbol(Empresa *empresas[], int cantidadEmpresas);
    void _ordenarEmpresasPorPrioridad(Empresa *empresa[], int cantidadEmpresas);
    void _dividirEmpresas(Empresa *empresas[], int cantidadEmpresas, Empresa *izquierdas[], Empresa *derechas[], int mediana);
    void _cantidades(Empresa *empresas[], int cantidadEmpresas, int mediana, int & cantidadIzquierda, int & cantidadDerecha);
    void _listarEmpresasPriorizadas(NodoArbolPrioridad * actual, Lista<Empresa> * empresas, int cantidadEmpleadosMinima, int cantidadEmpleadosMaxima, int rankingMaximo);
    void _destruir(NodoArbolPrioridad * actual);
    void _imprimirEmpresasArbolPrioridad(NodoArbolPrioridad *A);
public:
    ArbolPrioridad(Empresa * empresas[], int cantidadEmpresas);
    ~ArbolPrioridad();

    void listarEmpresasPriorizadas(Lista<Empresa> * empresas, int cantidadEmpleadosMinima, int cantidadEmpleadosMaxima, int rankingMaximo);
    void imprimirEmpresasArbolPrioridad();
};


#endif //CONSULTORA_ARBOLPRIORIDAD_H
