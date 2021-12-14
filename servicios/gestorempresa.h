#ifndef CONSULTORA_GESTOREMPRESA_H
#define CONSULTORA_GESTOREMPRESA_H

#include "../dominio/empresa.h"
#include "../estructuras/lista.h"
#include "../estructuras/arbol.h"
#include "../estructuras/arbolprioridad.h"


class GestorEmpresa {
private:
    int empresasAgregadas = 0;
    Empresa ** empresasPorPosicion;
    Arbol * empresasOrdenadasPorRazonSocial;
    ArbolPrioridad * arbolPrioridad;

public:
    GestorEmpresa(int cantidadEmpresas);
    ~GestorEmpresa();

    void agregarEmpresa(Empresa * empresa);
    Empresa * obtenerEmpresaPorPosicion(int posicion);
    Empresa * obtenerEmpresaPorRazonSocial(std::string razonSocial);
    Lista<Empresa> * listarEmpresasPorNumeroEmpleados(int desde, int hasta);
    Lista<Empresa> * listarEmpresasPorNumeroEmpleadosPriorizadas(int desde, int hasta, int rankingMaximo);
    void imprimirArbolPrioridad();
    void priorizarEmpresas(int cantidadEmpresas);
};


#endif //CONSULTORA_GESTOREMPRESA_H
