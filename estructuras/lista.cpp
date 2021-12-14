#include "lista.h"
#include "../dominio/empresa.h"

template<typename T>
Lista<T>::Lista() {
    this->primero = nullptr;
}

template <typename T>
Lista<T>::~Lista() {
    NodoLista<T>* actual = this->primero;
    while (actual != nullptr) {
        NodoLista<T>* siguiente = primero->siguiente;
        delete actual;
        actual = siguiente;
    }
    this->primero = nullptr;
}

template <typename T>
void Lista<T>::agregar(T * dato) {
    NodoLista<T> *nuevoNodoLista = new NodoLista<T>(dato);

    if (this->primero == nullptr) {
        primero = nuevoNodoLista;
    } else {
        nuevoNodoLista->siguiente = primero;
        primero = nuevoNodoLista;
    }
}

template<typename T>
NodoLista<T> *Lista<T>::obtenerPrimero() {
    return this->primero;
}

template class Lista<Empresa>;