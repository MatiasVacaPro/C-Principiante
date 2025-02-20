//Programa que elimina los negativos de un arreglo y los conveirte en 0
// Created by Nicole Vaca on 1/22/25.
//

#include <iostream>
#include <array>
using namespace std;
int main(){
    array<int, 8> numeros = {6,5,-8-9,7,5,-3,8};
    cout << "Arreglo original: " << endl;
    for(int &i : numeros){

      if (i<0) {
        i = 0;
      }

    }

    cout << endl;
    cout << "Arreglo modificado: " << endl;
    for(int &i : numeros){
      cout << i << " ";
    }


  cout << endl;
  cout << "El progrmama ha terminador";
  return 0;





  }
