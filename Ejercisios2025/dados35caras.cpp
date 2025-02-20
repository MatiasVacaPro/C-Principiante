// Programa que almacena la cantidad de veces que ha aparecido una cara de un dado
// Created by Nicole Vaca on 1/13/25.
// Version 1.0.0.0

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define CARA 7
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Semilla para generar numeros aleatorios
    int lanzamientos[CARA] = {0};

    // Definir 6000000 de lanzamientos de dados
    for (int lance = 1; lance <= 120000000; lance++) {
        size_t cara = rand() % 6;
        lanzamientos[cara]++;
    }

    cout << "Cara" << setw(6) << "Frecuencia" << endl;
    for (size_t i = 1; i <= 6; i++) {
        cout << i << setw(15) << lanzamientos[i] << endl;
    }

    // Generar lanzamientos adicionales para dos dados
    cout << "\nLanzamientos de dos dados:" << endl;
    cout << "Lanzamiento" << setw(10) << "Dado6" << setw(10) << "Dado35" << endl;

    for (int i = 1; i <= 20; i++) {
        int dado6 = (rand() % 6) + 1; // Dado de 6 caras
        int dado35 = (rand() % 35) + 1; // Dado de 35 caras
        cout << setw(10) << i << setw(10) << dado6 << setw(10) << dado35 << endl;
    }

    cout << "El programa ha terminado" << endl;
    return 0;
}

/*
<<iomanip>>
- Es una biblioteca de cabecera en C++ utilizada para la manipulación de entradas y salidas (I/O).
- Funciones principales:
  - setw(): Define el ancho del campo para el próximo dato que se mostrará.
  - setprecision(): Establece la precisión para mostrar números en punto flotante.
  - fixed: Fija la salida en formato decimal (no científico).
  - showpoint: Muestra el punto decimal incluso si es un número entero.
  - left y right: Alinea la salida a la izquierda o derecha dentro del ancho de campo especificado.

Uso:
- Permite formatear salidas con alineación, precisión y otros formatos.
- Ejemplo:
  cout << setw(10) << left << "Texto" << setprecision(2) << fixed << 3.14159 << endl;

Bibliografía:
- Documentación oficial de C++: https://cplusplus.com/reference/iomanip/
- "The C++ Programming Language" por Bjarne Stroustrup
*/
