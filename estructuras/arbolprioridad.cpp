#include "arbolprioridad.h"
#include <iostream>

ArbolPrioridad::~ArbolPrioridad() {
    this->_destruir(this->raiz);
}

void ArbolPrioridad::_destruir(NodoArbolPrioridad *actual) {
    if (actual != nullptr) {
        this->_destruir(actual->izq);
        this->_destruir(actual->der);
        delete actual;
    }
}

ArbolPrioridad::ArbolPrioridad(Empresa *empresas[], int cantidadEmpresas) {
    this->raiz = this->_construirArbol(empresas, cantidadEmpresas);
}

int ArbolPrioridad::_calcularMediana(Empresa * empresas[], int cantidadEmpresas) {

    Empresa * empresasOrdenadasPorEmpleados[cantidadEmpresas];

    this->_ordernarEmpresasPorCantidadEmpleados(empresas, cantidadEmpresas, empresasOrdenadasPorEmpleados);

    if (cantidadEmpresas % 2 == 0) {
        int medios =
                empresasOrdenadasPorEmpleados[cantidadEmpresas/2]->obtenerCantidadEmpleados() +
                empresasOrdenadasPorEmpleados[cantidadEmpresas/2 - 1]->obtenerCantidadEmpleados();
        return (medios/2);
    }
    return empresasOrdenadasPorEmpleados[(cantidadEmpresas)/2]->obtenerCantidadEmpleados();
}

void ArbolPrioridad::_ordernarEmpresasPorCantidadEmpleados(Empresa * empresas[], int cantidadEmpresas, Empresa * ordenado[]) {

    std::copy(empresas + 1, empresas + cantidadEmpresas + 1, ordenado); // ignoro el primero

    Empresa * aux;
    for (int i = 0; i < cantidadEmpresas - 1; i++) {
        for (int j = 0; j < (cantidadEmpresas - i - 1); j++) {
            if (ordenado[j]->obtenerCantidadEmpleados() > ordenado[j + 1]->obtenerCantidadEmpleados()) {
                aux = ordenado[j];
                ordenado[j] = ordenado[j + 1];
                ordenado[j + 1] = aux;
            }
        }
    }
}

void ArbolPrioridad::_cantidades(Empresa * empresas[], int cantidadEmpresas, int mediana, int & cantidadIzquierda, int & cantidadDerecha) {
    cantidadIzquierda = 0;
    cantidadDerecha = 0;

    for (int i = 1; i < cantidadEmpresas; i++) { // empiezo desde 1 porque ignoro el primero
        if (empresas[i]->obtenerCantidadEmpleados() < mediana) {
            cantidadIzquierda++;
        } else {
            cantidadDerecha++;
        }
    }
}

void ArbolPrioridad::_dividirEmpresas(
        Empresa* empresas[], int cantidadEmpresas, Empresa* izquierdas[], Empresa * derechas[], int mediana) {

    int contadorIzquierda = 0;
    int contadorDerecha = 0;

    for (int i = 1; i < cantidadEmpresas; i++) { //Empiezo desde 1 porque ignoro el primero
        if (empresas[i]->obtenerCantidadEmpleados() < mediana) {
            izquierdas[contadorIzquierda] = empresas[i];
            contadorIzquierda++;
        } else {
            derechas[contadorDerecha] = empresas[i];
            contadorDerecha++;
        }
    }
}

NodoArbolPrioridad * ArbolPrioridad::_construirArbol(Empresa *empresas[], int cantidadEmpresas) {
    if (cantidadEmpresas > 1) {
        Empresa * empresaConMenorPrioridad = empresas[0];
        int mediana = this->_calcularMediana(empresas, cantidadEmpresas - 1);

        int cantidadEmpresasIzquieda = 0;
        int cantidadEmpresasDerecha = 0;

        this->_cantidades(empresas, cantidadEmpresas, mediana, cantidadEmpresasIzquieda, cantidadEmpresasDerecha);

        Empresa ** empresasIzquierda = new Empresa*[cantidadEmpresasIzquieda];
        Empresa ** empresasDerecha = new Empresa*[cantidadEmpresasDerecha];

        this->_dividirEmpresas(
                empresas,
                cantidadEmpresas,
                empresasIzquierda,
                empresasDerecha,
                mediana);

        NodoArbolPrioridad * izquierda = this->_construirArbol(empresasIzquierda, cantidadEmpresasIzquieda);
        NodoArbolPrioridad * derecha = this->_construirArbol(empresasDerecha, cantidadEmpresasDerecha);

        NodoArbolPrioridad * nodoActual = new NodoArbolPrioridad(empresaConMenorPrioridad, mediana, izquierda, derecha);
        return nodoActual;
    }

    return nullptr;
}

void ArbolPrioridad::_listarEmpresasPriorizadas(NodoArbolPrioridad *actual, Lista<Empresa> *empresas,
                                                int cantidadEmpleadosMinima, int cantidadEmpleadosMaxima,
                                                int rankingMaximo) {

    if (actual != nullptr) {
        Empresa *empresaActual = actual->empresa;
        if (actual->izq != nullptr || actual->der != nullptr) {

            if (empresaActual->obtenerRanking() <= rankingMaximo) {
                if (empresaActual->obtenerCantidadEmpleados() <= cantidadEmpleadosMaxima &&
                    empresaActual->obtenerCantidadEmpleados() >= cantidadEmpleadosMinima) {

                    empresas->agregar(empresaActual);
                }

                if (actual->mediana > cantidadEmpleadosMinima) {
                    this->_listarEmpresasPriorizadas(
                            actual->izq, empresas, cantidadEmpleadosMinima, cantidadEmpleadosMaxima, rankingMaximo);
                }

                if (actual->mediana < cantidadEmpleadosMaxima) {
                    this->_listarEmpresasPriorizadas(
                            actual->der, empresas, cantidadEmpleadosMinima, cantidadEmpleadosMaxima, rankingMaximo);
                }
            }
        } else {
            // es hoja
            if (empresaActual->obtenerRanking() <= rankingMaximo &&
                empresaActual->obtenerCantidadEmpleados() >= cantidadEmpleadosMinima &&
                empresaActual->obtenerCantidadEmpleados() <= cantidadEmpleadosMaxima) {

                empresas->agregar(empresaActual);
            }
        }
    }
}

void ArbolPrioridad::listarEmpresasPriorizadas(Lista<Empresa> * empresas, int cantidadEmpleadosMinima, int cantidadEmpleadosMaxima, int rankingMaximo) {
    this->_listarEmpresasPriorizadas(this->raiz, empresas, cantidadEmpleadosMinima, cantidadEmpleadosMaxima, rankingMaximo);
}

void ArbolPrioridad::imprimirEmpresasArbolPrioridad() {
    this->_imprimirEmpresasArbolPrioridad(this->raiz);
}

void ArbolPrioridad::_imprimirEmpresasArbolPrioridad(NodoArbolPrioridad *A) {
    if (A != NULL) {
        _imprimirEmpresasArbolPrioridad(A->izq);
        std::cout << A->empresa->obtenerRazonSocial() << std::endl;
        std::cout << A->mediana << std::endl;
        _imprimirEmpresasArbolPrioridad(A->der);
    }
}
