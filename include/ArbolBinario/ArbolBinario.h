#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"
#include <iostream>
#include <stack>

template <typename T>
class ArbolBinario {
private:
    Nodo<T>* raiz;

    // Métodos auxiliares
    int obtenerAltura(Nodo<T>* nodo) {
        return nodo ? nodo->altura : 0;
    }

    int obtenerFactorBalance(Nodo<T>* nodo) {
        return nodo ? obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho) : 0;
    }

    Nodo<T>* rotacionDerecha(Nodo<T>* y) {
        Nodo<T>* x = y->izquierdo;
        Nodo<T>* T2 = x->derecho;

        x->derecho = y;
        y->izquierdo = T2;

        y->altura = 1 + maximo(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho));
        x->altura = 1 + maximo(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho));

        return x;
    }

    Nodo<T>* rotacionIzquierda(Nodo<T>* x) {
        Nodo<T>* y = x->derecho;
        Nodo<T>* T2 = y->izquierdo;

        y->izquierdo = x;
        x->derecho = T2;

        x->altura = 1 + maximo(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho));
        y->altura = 1 + maximo(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho));

        return y;
    }

    // Función para calcular el máximo entre dos números
    int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    // Método para balancear el árbol
    void balancear(Nodo<T>*& nodo) {
        if (!nodo) return;

        nodo->altura = 1 + maximo(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

        int balance = obtenerFactorBalance(nodo);

        if (balance > 1 && obtenerFactorBalance(nodo->izquierdo) >= 0) {
            nodo = rotacionDerecha(nodo);
        } else if (balance > 1 && obtenerFactorBalance(nodo->izquierdo) < 0) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            nodo = rotacionDerecha(nodo);
        } else if (balance < -1 && obtenerFactorBalance(nodo->derecho) <= 0) {
            nodo = rotacionIzquierda(nodo);
        } else if (balance < -1 && obtenerFactorBalance(nodo->derecho) > 0) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            nodo = rotacionIzquierda(nodo);
        }
    }

public:
    // Constructor
    ArbolBinario() : raiz(nullptr) {}

    // Métodos principales
    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!raiz) {
            raiz = nuevo;
            return;
        }

        Nodo<T>* actual = raiz;
        Nodo<T>* padre = nullptr;

        while (actual) {
            padre = actual;
            if (valor < actual->dato) {
                actual = actual->izquierdo;
            } else if (valor > actual->dato) {
                actual = actual->derecho;
            } else {
                delete nuevo; // Valor duplicado
                return;
            }
        }

        if (valor < padre->dato) {
            padre->izquierdo = nuevo;
        } else {
            padre->derecho = nuevo;
        }

        balancear(raiz);
    }

    void eliminar(T valor) {
        Nodo<T>* actual = raiz;
        Nodo<T>* padre = nullptr;

        while (actual && actual->dato != valor) {
            padre = actual;
            if (valor < actual->dato) {
                actual = actual->izquierdo;
            } else {
                actual = actual->derecho;
            }
        }

        if (!actual) {
            std::cout << "Valor no encontrado en el arbol." << std::endl;
            return;
        }

        if (!actual->izquierdo && !actual->derecho) {
            if (!padre) {
                raiz = nullptr;
            } else if (padre->izquierdo == actual) {
                padre->izquierdo = nullptr;
            } else {
                padre->derecho = nullptr;
            }
            delete actual;
        } else if (!actual->izquierdo || !actual->derecho) {
            Nodo<T>* hijo = actual->izquierdo ? actual->izquierdo : actual->derecho;
            if (!padre) {
                raiz = hijo;
            } else if (padre->izquierdo == actual) {
                padre->izquierdo = hijo;
            } else {
                padre->derecho = hijo;
            }
            delete actual;
        } else {
            Nodo<T>* sucesor = actual->derecho;
            Nodo<T>* padreSucesor = actual;
            while (sucesor->izquierdo) {
                padreSucesor = sucesor;
                sucesor = sucesor->izquierdo;
            }

            actual->dato = sucesor->dato;

            if (padreSucesor->izquierdo == sucesor) {
                padreSucesor->izquierdo = sucesor->derecho;
            } else {
                padreSucesor->derecho = sucesor->derecho;
            }

            delete sucesor;
        }

        balancear(raiz);
    }

    void imprimirEnOrden() {
        if (!raiz) {
            std::cout << "El arbol esta vacio." << std::endl;
            return;
        }

        std::stack<Nodo<T>*> pila;
        Nodo<T>* actual = raiz;

        while (!pila.empty() || actual) {
            while (actual) {
                pila.push(actual);
                actual = actual->izquierdo;
            }

            actual = pila.top();
            pila.pop();

            std::cout << actual->dato << " ";

            actual = actual->derecho;
        }
        std::cout << std::endl;
    }
};

#endif // ARBOLBINARIO_H
