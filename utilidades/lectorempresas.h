#ifndef CONSULTORA_LECTOREMPRESAS_H
#define CONSULTORA_LECTOREMPRESAS_H


#include "../dominio/empresa.h"

class LectorEmpresas {

public:
    LectorEmpresas() {};
    Empresa * leerEmpresa(std::string empresa, int ranking);
};


#endif //CONSULTORA_LECTOREMPRESAS_H
