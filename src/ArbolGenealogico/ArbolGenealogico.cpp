#include "../../include/ArbolGenealogico/ArbolGenealogico.h"


// Constructor
ArbolGenealogico::ArbolGenealogico(const std::string& nombreRaiz) {
    raiz = new NodoGenealogico(nombreRaiz);
}

// Destructor
ArbolGenealogico::~ArbolGenealogico() {
    delete raiz; // Liberar memoria asociada al árbol
}

// Agregar un hijo a un nodo
void ArbolGenealogico::agregarHijo(NodoGenealogico* padre, const std::string& nombreHijo) {
    NodoGenealogico* nuevoHijo = new NodoGenealogico(nombreHijo);
    nuevoHijo->padre = padre;

    if (!padre->hijo) {
        padre->hijo = nuevoHijo;
    } else {
        NodoGenealogico* temp = padre->hijo;
        while (temp->hermano) {
            temp = temp->hermano;
        }
        temp->hermano = nuevoHijo;
    }
}

// Buscar un nodo por nombre
NodoGenealogico* ArbolGenealogico::buscarNodo(NodoGenealogico* nodo, const std::string& nombre) {
    if (!nodo) return nullptr;

    if (nodo->nombre == nombre) return nodo;

    NodoGenealogico* encontrado = buscarNodo(nodo->hijo, nombre);
    if (encontrado) return encontrado;

    return buscarNodo(nodo->hermano, nombre);
}

// Agregar un nodo al árbol
void ArbolGenealogico::agregarNodo(const std::string& nombrePadre, const std::string& nombreHijo) {
    NodoGenealogico* nodoPadre = buscarNodo(raiz, nombrePadre);
    if (nodoPadre) {
        agregarHijo(nodoPadre, nombreHijo);
    } else {
        std::cout << "Padre " << nombrePadre << " no encontrado." << std::endl;
    }
}

// Recorrer e imprimir el árbol
void ArbolGenealogico::recorrer(NodoGenealogico* nodo, int nivel) const {
    if (!nodo) return;

    for (int i = 0; i < nivel; ++i) {
        std::cout << "--";
    }
    std::cout << nodo->nombre << std::endl;

    recorrer(nodo->hijo, nivel + 1);
    recorrer(nodo->hermano, nivel);
}

void ArbolGenealogico::imprimir() const {
    recorrer(raiz, 0);
}
