#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato;                    
    Nodo* izquierdo;           
    Nodo* derecho;             
    int altura;                

    // Constructor
    Nodo(T valor) : dato(valor), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};

#endif // NODO_H
