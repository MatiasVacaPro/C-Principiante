//
// Created by Nicole Vaca on 2/3/25.
//

#include <array>
#include <iostream>
using namespace std;
int main () {
  array<int, 5> numeros = {10, 20, 30, 40, 50};

  int * numPtr=numeros.data();
  cout << numPtr <<" " << endl;
  cout << numPtr <<" " << *(numPtr+1) << endl;
   for (size_t i=0; i<numeros.size(); i++)
     cout  <<*(numPtr+i) << endl;

  // Busqueda de un elemento en el arreglo
  int busqueda = 3;
  bool encontrado = false;
  for (int i = 0; i < numeros.size(); i++) {
    if (numeros[i] == busqueda) {
      encontrado = true;
      break;
    }
  }

  if (encontrado) {
    cout << "El elemento " << busqueda << " se ha encontrado en el arreglo." << endl;
  } else {
    cout << "El elemento " << busqueda << " no se ha encontrado en el arreglo." << endl;
  }

  return 0;
}
