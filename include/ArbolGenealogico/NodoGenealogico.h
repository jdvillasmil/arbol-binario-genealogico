#ifndef NODOGENEALOGICO_H
#define NODOGENEALOGICO_H

#include <string>

class NodoGenealogico {
public:
    std::string nombre;
    NodoGenealogico* padre;
    NodoGenealogico* hijo;
    NodoGenealogico* hermano;

    NodoGenealogico(const std::string& nombre)
        : nombre(nombre), padre(nullptr), hijo(nullptr), hermano(nullptr) {}
};

#endif // NODOGENEALOGICO_H
