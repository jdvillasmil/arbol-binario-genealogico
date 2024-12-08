#include "../../include/ArbolBinario/ArbolBinario.h"
#include <iostream>

int main() {
    ArbolBinario<int> arbol;

    // Insertar valores
    arbol.insertar(30);
    arbol.insertar(20);
    arbol.insertar(40);
    arbol.insertar(10);
    arbol.insertar(25);
    arbol.insertar(35);
    arbol.insertar(50);

    std::cout << "Recorrido en orden despues de las inserciones:" << std::endl;
    arbol.imprimirEnOrden();

    // Eliminar valores
    arbol.eliminar(20);
    arbol.eliminar(30);
    arbol.eliminar(10);

    std::cout << "Recorrido en orden despues de las eliminaciones:" << std::endl;
    arbol.imprimirEnOrden();

    return 0;
}
