#ifndef NODOGENEALOGICO_H
#define NODOGENEALOGICO_H

#include <string>

class NodoGenealogico {
public:
    std::string nombre;               // Nombre de la persona
    NodoGenealogico* padre;           // Puntero al nodo del padre
    NodoGenealogico* hijo;            // Puntero al primer hijo
    NodoGenealogico* hermano;         // Puntero al siguiente hermano

    // Constructor
    NodoGenealogico(const std::string& nombrePersona)
        : nombre(nombrePersona), padre(nullptr), hijo(nullptr), hermano(nullptr) {}

    // Destructor
    ~NodoGenealogico() {
        delete hijo;   // Liberar memoria del subarbol de hijos
        delete hermano; // Liberar memoria de los hermanos
    }
};

#endif // NODOGENEALOGICO_H
