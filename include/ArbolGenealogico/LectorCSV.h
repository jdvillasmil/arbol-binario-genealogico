#ifndef LECTORCSV_H
#define LECTORCSV_H

#include "ArbolGenealogico.h"

class LectorCSV {
private:
    ArbolGenealogico* arbol;

    // Método para separar una línea en padre e hijo
    void separarLinea(const char* linea, char* padre, char* hijo);

public:
    LectorCSV(ArbolGenealogico* arbolGenealogico);
    void leerArchivo(const char* rutaArchivo);
};

#endif // LECTORCSV_H
