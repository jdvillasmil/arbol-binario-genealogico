###########################################
#          PROYECTO: ÁRBOL BINARIO        #
#           Y ÁRBOL GENEALÓGICO           #
###########################################

Descripción:
------------
Este proyecto implementa dos estructuras principales:
1. **Árbol Binario Balanceado**: Permite insertar y eliminar nodos de manera no recursiva, manteniendo el balance del árbol.
2. **Árbol Genealógico**: Construye y organiza un árbol genealógico a partir de un archivo CSV, permitiendo registrar relaciones padre-hijo y hermanos.

Estructura del Proyecto:
-------------------------
- `include/`: Contiene los archivos de cabecera del proyecto.
    - `ArbolBinario.h`: Implementación del árbol binario.
    - `Nodo.h`: Nodo genérico utilizado por las estructuras.
    - `NodoGenealogico.h`: Nodo específico para el árbol genealógico.
    - `ArbolGenealogico.h`: Implementación del árbol genealógico.
    - `LectorCSV.h`: Clase para leer archivos CSV y construir el árbol genealógico.

- `src/ArbolBinario/`: Contiene los archivos fuente relacionados con el árbol binario.
    - `PruebasArbolBinario.cpp`: Pruebas para el árbol binario.

- `src/ArbolGenealogico/`: Contiene los archivos fuente relacionados con el árbol genealógico.
    - `ArbolGenealogico.cpp`: Funciones del árbol genealógico.
    - `LectorCSV.cpp`: Implementación del lector de archivos CSV.
    - `PruebasGenealogicas.cpp`: Pruebas para el árbol genealógico.

- `datos/`: Carpeta que contiene los archivos CSV de entrada.
    - `ejemplo.csv`: Archivo de ejemplo para construir el árbol genealógico.

- `README.txt`: Este archivo.

Compilación:
------------
Para compilar el proyecto, utiliza los siguientes comandos:

1. Para el árbol binario:
g++ -o pruebasArbolBinario src/ArbolBinario/PruebasArbolBinario.cpp -Iinclude

2. Para el árbol genealógico:
g++ -o pruebasGenealogicas src/ArbolGenealogico/*.cpp -Iinclude

Ejecución:
----------
1. Para probar el árbol binario:
./pruebasArbolBinario

Salida esperada:
Recorrido en orden despues de las inserciones: 10 20 25 30 35 40 50 Recorrido en orden despues de las eliminaciones: 25 35 40 50

2. Para probar el árbol genealógico:
./pruebasGenealogicas

Entrada esperada (`datos/ejemplo.csv`):
Juan,Pedro Juan,Maria Pedro,Luis Maria,Sofia

Salida esperada:
Arbol Genealogico: Juan --Pedro ----Luis --Maria ----Sofia

Requisitos:
-----------
1. No se utilizan librerías externas. Todo el código es implementado manualmente.
2. El compilador debe soportar C++17 o superior.

Autores:
--------
Este proyecto fue desarrollado como parte de la materia **Estructura Dinámica de Datos**. La implementación es completamente personalizada y cumple con los requerimientos establecidos.

