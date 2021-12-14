#ifndef CONSULTORA_LISTA_H
#define CONSULTORA_LISTA_H

template <typename T>
struct NodoLista {
    NodoLista(T * dato): dato(dato), siguiente(nullptr) {}

    T * dato;
    NodoLista * siguiente;
};

template <typename T>
class Lista {
private:
    NodoLista<T> * primero;

public:
    Lista();
    ~Lista();

    void agregar(T * dato);
    NodoLista<T> * obtenerPrimero();
};


#endif //CONSULTORA_LISTA_H
