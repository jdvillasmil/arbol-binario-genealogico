#include "../../include/ArbolGenealogico/LectorCSV.h"


int main() {
    // Crear un árbol genealógico con la raíz "Juan"
    ArbolGenealogico arbol("Juan");

    // Leer nodos desde el archivo CSV
    LectorCSV lector(&arbol);
    lector.leerArchivo("datos/ejemplo.csv");

    // Imprimir el árbol genealógico
    std::cout << "Arbol Genealogico:" << std::endl;
    arbol.imprimir();

    return 0;
}
