//Programa para calcular la rotacion de una matriz
// Created by Nicole Vaca on 1/20/25.
//

#include <iostream>
using namespace std;
// Declacriacion de funciones
void rotarMatrix(int[3][3], int n);
int main(){

  int a[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  for (int  i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << a[i][j] <<" ";
    }
    cout << endl;
  }
    cout << "El programa ha terminado" << endl;

}

void rotarMatrix(int matrix[3][3], int n) {
  int resultado [3][3]; // Una matriz bidimencional se le (a[n][m])
// rotacion de matriz
  for (int i = 0; i < n; i++) { //el n que se pasa como argumento es el que define el lkmite
    //Y que tiene que ser igual al tamaño del arreglo.impide conocer el tamaño en tiempoo de ejecución
    for (int j = 0; j < n; j++) {
      resultado[j][n - 1 - i] = matrix[i][j];
    }
  }
// imprimir matriz rotada
  cout << "Matriz rotada" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << resultado[i][j] << " ";
    }
    cout << endl;
  }

}