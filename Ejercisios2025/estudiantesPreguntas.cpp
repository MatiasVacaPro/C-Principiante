//Se pidió a 20 estudiantes que valoraran en una escala del 1 al 5 la calidad de
// la comida de la cafetería de estudiantes, siendo 1 «horrible» y 5 «excelente».
// Coloque las 20 respuestas en una matriz de números enteros y determine la
// frecuencia de cada valoración.

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;


// Definición de la matriz
void matriz(array<array<int, 20>,5>& b);


int main() {

  array<array<int, 20>,5> b;
  matriz(b);

  cout << "Terminar programacion";
  return 0;
}

void matriz(array<array<int, 20>,5>& b) {
  srand(time(0));
  // Inicializar el generador de números aleatorios
  // Llenar la matriz con valores aleatorios entre 1 y 5
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 5; j++) {
      b[i][j] = rand() % 5 + 1;
    }
  }

  // Imprimir la matriz
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 5; j++) {
      cout << b[i][j] << " ";
    }
    cout << endl;
  }
}