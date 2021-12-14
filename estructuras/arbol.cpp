#include "arbol.h"

 Arbol::~Arbol() {
    this->_destruir(this->raiz);
}

void Arbol::_destruir(NodoArbol *actual) {
    if (actual != nullptr) {
        this->_destruir(actual->izq);
        this->_destruir(actual->der);
        delete actual;
    }
}

void Arbol::_agregar(NodoArbol * actual, NodoArbol * nuevoNodo) {
    if (actual != nullptr) {
        if (actual->empresa->obtenerRazonSocial() < nuevoNodo->empresa->obtenerRazonSocial()) {
            if (actual->der == nullptr) {
                actual->der = nuevoNodo;
            } else {
                this->_agregar(actual->der, nuevoNodo);
            }
        } else {
            if (actual->izq == nullptr) {
                actual->izq = nuevoNodo;
            } else{
                this->_agregar(actual->izq, nuevoNodo);
            }
        }
    } else {
        this->raiz = nuevoNodo;
    }
}

Empresa *Arbol::_obtenerPorRazonSocial(NodoArbol * actual, std::string razonSocial) const {
    if (actual != nullptr) {
        std::string razonSocialActual = actual->empresa->obtenerRazonSocial();
        if (razonSocialActual == razonSocial) {
            return actual->empresa;
        } else if (razonSocialActual < razonSocial) {
            return this->_obtenerPorRazonSocial(actual->der, razonSocial);
        } else {
            return this->_obtenerPorRazonSocial(actual->izq, razonSocial);
        }
    }

    return nullptr;
}

void Arbol::agregar(Empresa *empresa) {
    NodoArbol * nuevoNodo = new NodoArbol(empresa);
    _agregar(this->raiz, nuevoNodo);
}

Empresa *Arbol::obtenerPorRazonSocial(std::string razonSocial) const {
    return this->_obtenerPorRazonSocial(this->raiz, razonSocial);
}
