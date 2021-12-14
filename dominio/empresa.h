#ifndef CONSULTORA_EMPRESA_H
#define CONSULTORA_EMPRESA_H

#include <string>

class Empresa {
private:
    std::string razonSocial;
    int cantidadEmpleados;
    int ranking;
    std::string pais;
    std::string rubro;

public:
    Empresa() {};
    Empresa(std::string razonSocial, int cantidadEmpleados, int ranking, std::string pais, std::string rubro);
    ~Empresa() = default;

    void establecerRazonSocial(std::string razonSocial);
    void establecerCantidadEmpleados(int cantidadEmpleados);
    void establecerRanking(int ranking);
    void establecerPais(std::string pais);
    void establecerRubro(std::string rubro);

    std::string obtenerRazonSocial() const;
    int obtenerCantidadEmpleados() const;
    int obtenerRanking() const;
    std::string obtenerPais() const;
    std::string obtenerRubro() const;
};

#endif //CONSULTORA_EMPRESA_H
