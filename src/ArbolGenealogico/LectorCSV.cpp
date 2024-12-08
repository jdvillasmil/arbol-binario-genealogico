#include "../../include/ArbolGenealogico/LectorCSV.h"

#include <cstdio>
#include <cstring>

// Constructor
LectorCSV::LectorCSV(ArbolGenealogico* arbolGenealogico) : arbol(arbolGenealogico) {}

// Leer archivo CSV y construir el árbol
void LectorCSV::leerArchivo(const char* rutaArchivo) {
    FILE* archivo = fopen(rutaArchivo, "r");
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return;
    }

    char linea[256];
    char padre[128];
    char hijo[128];

    while (fgets(linea, sizeof(linea), archivo)) {
        // Eliminar saltos de línea y espacios innecesarios
        size_t len = strlen(linea);
        if (len > 0 && (linea[len - 1] == '\n' || linea[len - 1] == '\r')) {
            linea[len - 1] = '\0';
        }

        // Separar la línea en padre e hijo
        separarLinea(linea, padre, hijo);

        // Validar que no haya datos vacíos
        if (strlen(padre) == 0 || strlen(hijo) == 0) {
            std::cerr << "Línea mal formada en el archivo: " << linea << std::endl;
            continue;
        }

        // Agregar el nodo al árbol
        arbol->agregarNodo(padre, hijo);
    }

    fclose(archivo);
}

// Separar la línea del archivo CSV
void LectorCSV::separarLinea(const char* linea, char* padre, char* hijo) {
    int i = 0, j = 0;

    // Leer el nombre del padre
    while (linea[i] != ',' && linea[i] != '\0') {
        if (linea[i] != ' ') { // Ignorar espacios
            padre[j++] = linea[i];
        }
        i++;
    }
    padre[j] = '\0';
    i++; // Saltar la coma

    // Leer el nombre del hijo
    j = 0;
    while (linea[i] != '\n' && linea[i] != '\0') {
        if (linea[i] != ' ') { // Ignorar espacios
            hijo[j++] = linea[i];
        }
        i++;
    }
    hijo[j] = '\0';
}