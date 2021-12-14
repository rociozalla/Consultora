#include "lectorempresas.h"

Empresa *LectorEmpresas::leerEmpresa(std::string linea, int ranking) {
    //Primer posici�n del separador ;
    int posInicial = 0;
    int posFinal = linea.find(";");

    //Informacion entre posInicial y posFinal
    std::string razonSocial = linea.substr(posInicial, posFinal);

    //Segunda posici�n del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    std::string pais = linea.substr(posInicial, posFinal - posInicial);

    //Tercera posici�n del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    int cantidadEmpleados = atoi(linea.substr(posInicial, posFinal - posInicial).c_str());

    //Cuarta posici�n del separador ;
    posInicial = posFinal + 1;
    posFinal = linea.find(";", posInicial);
    std::string rubro = linea.substr(posInicial, posFinal - posInicial);

    Empresa * empresa = new Empresa(razonSocial, cantidadEmpleados, ranking, pais, rubro);

    return empresa;
}
