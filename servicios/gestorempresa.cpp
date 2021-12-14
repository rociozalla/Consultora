#include "gestorempresa.h"

GestorEmpresa::GestorEmpresa(int cantidadEmpresas) {
    this->empresasPorPosicion = new Empresa*[cantidadEmpresas];
    this->empresasOrdenadasPorRazonSocial = new Arbol();
}

void GestorEmpresa::priorizarEmpresas(int cantidadEmpresas) {
    this->arbolPrioridad = new ArbolPrioridad(this->empresasPorPosicion, cantidadEmpresas);
}

Lista<Empresa> * GestorEmpresa::listarEmpresasPorNumeroEmpleados(int desde, int hasta) {
    Lista<Empresa> *lista = new Lista<Empresa>();
    Empresa * empresaActual;
    for(int i = 0; i < this->empresasAgregadas; i++) {
        empresaActual = this->empresasPorPosicion[i];
        if (empresaActual->obtenerCantidadEmpleados() >= desde && empresaActual->obtenerCantidadEmpleados() <= hasta)
            lista->agregar(empresaActual);
    }
    return lista;
}

void GestorEmpresa::agregarEmpresa(Empresa * empresa) {
    this->empresasPorPosicion[this->empresasAgregadas] = empresa;
    this->empresasAgregadas = this->empresasAgregadas + 1;
    this->empresasOrdenadasPorRazonSocial->agregar(empresa);
}

Empresa * GestorEmpresa::obtenerEmpresaPorPosicion(int posicion) {
    return this->empresasPorPosicion[posicion - 1];
}

Empresa *GestorEmpresa::obtenerEmpresaPorRazonSocial(std::string razonSocial) {
    return this->empresasOrdenadasPorRazonSocial->obtenerPorRazonSocial(razonSocial);
}

Lista<Empresa> *GestorEmpresa::listarEmpresasPorNumeroEmpleadosPriorizadas(int minimoEmpleados, int maximoEmpleados, int rankingMaximo) {
    Lista<Empresa>* empresasFiltradas = new Lista<Empresa>;

    this->arbolPrioridad->listarEmpresasPriorizadas(
            empresasFiltradas, minimoEmpleados, maximoEmpleados, rankingMaximo);

    return empresasFiltradas;
}

void GestorEmpresa::imprimirArbolPrioridad() {
    this->arbolPrioridad->imprimirEmpresasArbolPrioridad();
}
