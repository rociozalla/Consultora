#ifndef CONSULTORA_ARBOL_H
#define CONSULTORA_ARBOL_H

#include "../dominio/empresa.h"

struct NodoArbol {
    NodoArbol(Empresa * empresa): empresa(empresa), izq(nullptr), der(nullptr) {};
    Empresa * empresa;
    NodoArbol * izq;
    NodoArbol * der;
};

class Arbol {
private:
    NodoArbol * raiz;

    void _agregar(NodoArbol * actual, NodoArbol * nuevoNodoArbol);
    Empresa * _obtenerPorRazonSocial(NodoArbol * actual, std::string razonSocial) const;
    void _destruir(NodoArbol * actual);

public:
    Arbol(): raiz(nullptr) {};
    ~Arbol();

    void agregar(Empresa * empresa);
    Empresa * obtenerPorRazonSocial(std::string razonSocial) const;
};

#endif //CONSULTORA_ARBOL_H
