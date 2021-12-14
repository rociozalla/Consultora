#include "empresa.h"

Empresa::Empresa(std::string razonSocial, int cantidadEmpleados, int ranking, std::string pais, std::string rubro) {
    this->razonSocial = razonSocial;
    this->cantidadEmpleados = cantidadEmpleados;
    this->ranking = ranking;
    this->pais = pais;
    this->rubro = rubro;
}

std::string Empresa::obtenerRazonSocial() const {
    return this->razonSocial;
}

int Empresa::obtenerCantidadEmpleados() const {
    return this->cantidadEmpleados;
}

int Empresa::obtenerRanking() const {
    return this->ranking;
}

std::string Empresa::obtenerRubro() const {
    return this->rubro;
}

std::string Empresa::obtenerPais() const {
    return this->pais;
}

void Empresa::establecerRubro(std::string rubro) {
    this->rubro = rubro;
}

void Empresa::establecerRazonSocial(std::string razonSocial) {
    this->razonSocial = razonSocial;
}

void Empresa::establecerCantidadEmpleados(int cantidadEmpleados) {
    this->cantidadEmpleados = cantidadEmpleados;
}

void Empresa::establecerRanking(int ranking) {
    this->ranking = ranking;
}

void Empresa::establecerPais(std::string pais) {

}
