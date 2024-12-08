#ifndef ARBOLGENEALOGICO_H
#define ARBOLGENEALOGICO_H

#include "NodoGenealogico.h"
#include <iostream>

class ArbolGenealogico {
private:
    NodoGenealogico* raiz;

    // Método para agregar un hijo
    void agregarHijo(NodoGenealogico* padre, const std::string& nombreHijo);

    // Método para buscar un nodo por nombre
    NodoGenealogico* buscarNodo(NodoGenealogico* nodo, const std::string& nombre);

    // Método para recorrer e imprimir el árbol
    void recorrer(NodoGenealogico* nodo, int nivel) const;

public:
    ArbolGenealogico(const std::string& nombreRaiz);
    ~ArbolGenealogico();

    void agregarNodo(const std::string& nombrePadre, const std::string& nombreHijo);
    void imprimir() const;
};

#endif // ARBOLGENEALOGICO_H
