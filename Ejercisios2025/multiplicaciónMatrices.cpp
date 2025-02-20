//
// Created by Nicole Vaca on 1/21/25.
// Programa para multiplicar matrices

#include <iostream>
#include <array>
using namespace std;

// Declaración de funciones
void multiplicarM(const array<array<int, 4>, 3>& a, const array<array<int, 3>, 4>& b);

int main() {
  // Definición de matrices
  array<array<int, 4>, 3> a = {{{1, 1, 1, 2}, {2, 1, 1, 1}, {1, 2, 1, 1}}};
  array<array<int, 3>, 4> b = {{{0, 1, 1}, {2, 1, 1}, {2, 0, 1}, {1, 2, 0}}};

  // Llamada a la función para multiplicar matrices
  multiplicarM(a, b);

  cout << "El programa ha terminado";
  return 0;
}

// Definición de la función para multiplicar matrices
void multiplicarM(const array<array<int, 4>, 3>& a, const array<array<int, 3>, 4>& b) {
  // La matriz resultado tendrá las dimensiones adecuadas (3x3)
  array<array<int, 3>, 3> resultado = {};

  // Multiplicación de matrices
  for (size_t i = 0; i < resultado.size(); ++i) {
    for (size_t j = 0; j < resultado[i].size(); ++j) {
      resultado[i][j] = 0;
      for (size_t k = 0; k < a[i].size(); ++k) {
        resultado[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Mostrar la matriz resultado
  cout << "Resultado de la multiplicación:\n";
  for (const auto& fila : resultado) {
    for (const auto& elem : fila) {
      cout << elem << " ";
    }
    cout << endl;
  }
}
