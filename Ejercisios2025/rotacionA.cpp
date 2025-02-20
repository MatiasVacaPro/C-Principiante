// Programa para calcular la rotacion de una matriz
// Created by Nicole Vaca on 1/20/25.

#include <iostream>
#include <array>
using namespace std;

// Declaracion de funciones: Esta funcion realiza la rotacion de una matriz cuadrada de 3x3
void rotarMatrix(array<array<int, 3>, 3>& matriz);

int main() {
    // Definicion e inicializacion de la matriz original
    array<array<int, 3>, 3> a = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    // Mostrar la matriz original
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " "; // Imprime cada elemento de la fila actual
        }
        cout << endl; // Salto de linea al final de cada fila
    }

    // Llamada a la funcion para rotar la matriz
    rotarMatrix(a);

    // Mensaje de finalizacion
    cout << "El programa ha terminado" << endl;
    return 0;
}

void rotarMatrix(array<array<int, 3>, 3>& matriz) {
    // Definicion de la matriz para almacenar el resultado de la rotacion
    array<array<int, 3>, 3> resultado;

    // Rotacion de la matriz: se asigna cada elemento a su nueva posicion
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            resultado[j][matriz.size() - 1 - i] = matriz[i][j];
        }
    }

    // Mostrar la matriz rotada
    cout << "Matriz rotada" << endl;
    for (int i = 0; i < resultado.size(); i++) {
        for (int j = 0; j < resultado[i].size(); j++) {
            cout << resultado[i][j] << " "; // Imprime cada elemento de la fila actual
        }
        cout << endl; // Salto de linea al final de cada fila
    }
}
