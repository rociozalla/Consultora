#include <iostream>
#include <fstream>
#include "estructuras/lista.h"
#include "dominio/empresa.h"
#include "servicios/gestorempresa.h"
#include "utilidades/lectorempresas.h"

void buscarPorRazonSocial(GestorEmpresa *gestor, Empresa *empresaBuscada);

void buscarPorRanking(GestorEmpresa *gestor, Empresa *empresaBuscada);

void filtrarPorCantidadDeEmpleados(GestorEmpresa *gestor);

void filtrarPorCantidadDeEmpleadosYRankingMaximo(GestorEmpresa *gestor);

void menu(GestorEmpresa * gestor) {
    int opcion;

    while (true) {
        std::cout << "--------------------------------------------------------" << std::endl;
        std::cout << "1 - Obtener posicion de Empresa en el ranking" << std::endl;
        std::cout << "2 - Obtener informacion de la Empresa de acuerdo a la posicion" << std::endl;
        std::cout << "3 - Listar empresas y posicion por numero de empleados" << std::endl;
        std::cout << "4 - Obtener primeras n empresas segun numero de empleados" << std::endl;
        std::cout << "5 - Imprimir arbol prioridad" << std::endl;
        std::cout << "0 - Salir" << std::endl;
        std::cout << "Ingrese opcion: ";
        std::cin >> opcion;

        Empresa *empresaBuscada = nullptr;

        switch (opcion) {
            case 1: {
                buscarPorRazonSocial(gestor, empresaBuscada);
                break;
            }
            case 2: {
                buscarPorRanking(gestor, empresaBuscada);
                break;
            }
            case 3: {
                filtrarPorCantidadDeEmpleados(gestor);
                break;
            }
            case 4: {
                filtrarPorCantidadDeEmpleadosYRankingMaximo(gestor);
                break;
            }
            case 5: {
                gestor->imprimirArbolPrioridad();
                break;
            }
            case 0: {
                std::cout << "Hasta luego" << std::endl;
                return;
            }
            default: {
                std::cout << "Ingrese una opcion valida" << std::endl;
            }
        }
    }
}

void filtrarPorCantidadDeEmpleadosYRankingMaximo(GestorEmpresa *gestor) {
    int minEmpleados, maxEmpleados, rankingMaximo;
    std::cout << "Ingrese el numero minimo de empleados";
    std::cin >> minEmpleados;
    std::cout << "Ingrese el numero maximo de empleados";
    std::cin >> maxEmpleados;
    std::cout << "Ingrese el numero de ranking maximo";
    std::cin >> rankingMaximo;

    if (minEmpleados > maxEmpleados) {
        int auxiliar;
        auxiliar = minEmpleados;
        minEmpleados = maxEmpleados;
        maxEmpleados = auxiliar;
    }

    Lista<Empresa> *empresasFiltradas =
            gestor->listarEmpresasPorNumeroEmpleadosPriorizadas(minEmpleados, maxEmpleados, rankingMaximo);

    NodoLista<Empresa> *cursor = empresasFiltradas->obtenerPrimero();

    while (cursor != nullptr) {
        std::cout << "Nombre: " << cursor->dato->obtenerRazonSocial() << std::endl;
        std::cout << "Posicion: " << cursor->dato->obtenerRanking() << std::endl;
        std::cout << "Cantidad de empleados: " << cursor->dato->obtenerCantidadEmpleados() << std::endl;
        cursor = cursor->siguiente;
    }
}

void filtrarPorCantidadDeEmpleados(GestorEmpresa *gestor) {
    int minEmpleados, maxEmpleados;
    std::cout << "Ingrese el numero minimo de empleados";
    std::cin >> minEmpleados;
    std::cout << "Ingrese el numero maximo de empleados";
    std::cin >> maxEmpleados;

    if (minEmpleados > maxEmpleados) {
        int auxiliar;
        auxiliar = minEmpleados;
        minEmpleados = maxEmpleados;
        maxEmpleados = auxiliar;
    }

    Lista<Empresa> *listaEmpleados = gestor->listarEmpresasPorNumeroEmpleados(minEmpleados, maxEmpleados);

    NodoLista<Empresa> *cursor = listaEmpleados->obtenerPrimero();

    while (cursor != nullptr) {
        std::cout << "Nombre: " << cursor->dato->obtenerRazonSocial() << std::endl;
        std::cout << "Posicion: " << cursor->dato->obtenerRanking() << std::endl;
        cursor = cursor->siguiente;
    }
}

void buscarPorRanking(GestorEmpresa *gestor, Empresa *empresaBuscada) {
    std::cout << "Ingrese la posicion de la empresa buscada: ";
    int posicion;
    std::cin >> posicion;
    empresaBuscada = gestor->obtenerEmpresaPorPosicion(posicion);
    if (empresaBuscada != nullptr) {
        std::cout << "La empresa en la posicion solicitada es: " << std::endl;
        std::cout << "razon social: " << empresaBuscada->obtenerRazonSocial() << std::endl;
        std::cout << "pais: " << empresaBuscada->obtenerPais() << std::endl;
        std::cout << "cantidad de empleados: " << empresaBuscada->obtenerCantidadEmpleados() << std::endl;
        std::cout << "rubro: " << empresaBuscada->obtenerRubro() << std::endl;
        std::cout << "ranking: " << empresaBuscada->obtenerRanking() << std::endl;
    } else {
        std::cout << "Ingrese una posicion valida.";
    }
}

void buscarPorRazonSocial(GestorEmpresa *gestor, Empresa *empresaBuscada) {
    std::string razonSocial;
    std::cout << "Ingrese el nombre de la empresa: " << std::endl;
    std::cin.ignore(1, '\n');
    std::getline(std::cin, razonSocial);
    empresaBuscada = gestor->obtenerEmpresaPorRazonSocial(razonSocial);
    if (empresaBuscada != nullptr) {
        std::cout << "La empresa " << empresaBuscada->obtenerRazonSocial()
                  << " se ubica en la posicion numero " << empresaBuscada->obtenerRanking()
                  << std::endl;
    }
}

int main() {

    std::ifstream archivo("../ranking_empresas.csv");
    std::string linea;
    int ranking = 1;
    Empresa * empresaLeida;

    LectorEmpresas lectorEmpresas;
    if (!archivo.is_open())
        std::cout << "No se pudo abrir el archivo. " << std::endl;
    else {
        getline(archivo, linea);
        int cantidadEmpresas = std::stoi(linea);

        GestorEmpresa * gestor = new GestorEmpresa(cantidadEmpresas);

        while (getline(archivo, linea)) {
            empresaLeida = lectorEmpresas.leerEmpresa(linea, ranking);
            gestor->agregarEmpresa(empresaLeida);
            ranking++;
        }

        gestor->priorizarEmpresas(cantidadEmpresas);

        menu(gestor);
    }

    return 0;
}
