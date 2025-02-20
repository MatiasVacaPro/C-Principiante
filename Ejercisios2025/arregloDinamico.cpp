//Programa que lee, modifica y copia RREGLOS DINAMICOS
// Created by Nicole Vaca on 1/22/25.

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector> // Esta permite la bliblioteca que permite la  gestion de arreglos dinamicos y todas
using namespace std;
//Definición de funciones
void vectorSalida(vector<int>&);// Se consiudefra constante durante todo el procedimeiento
// , lo que evita cualquier modificación interna no planificada
void vectorEntrada(vector<int>&);


int main() {
  vector<int> vector1(7);
  vector<int> vector2(10);

  cout << "El tamanio del vector 1 es: " << vector1.size() << "\nEl vector en su inciio es: " ;
   cout  << vectorSalida(vector1);

   cout << "Llenando el arreglo\n ";
           vectorEntrada(vector1);
           vectorEntrada(vector2);

cout << "Desoues de  la agregación se obtiene: \n vecto";
  vectorSalida(vector1);
  cout << "\n vector2: ";

if (vector1 != vector2){
cout << "Los vectores no son iguales" << endl;
}else{
  cout << "Los vectores son iguales" << endl;
  }
  cout << "El progradas was ended";
   return 0;
}
// copia de cionstructor de arreglos vectores
vector<int> vector3(vector1)
// Declaracion de funciones
void vectorSalida(const vector<int>& items) {
  for(int i: items){
    cout << i << "";
  }
  cout << endl;
  }

void vectorEntrada(vector<int>& items) {
  cout << "Ingrese los valores de cada espacio, separado por enter: "
 for(int& i: items){

   cin >> i;
   cin.ignore(numeric:limits<streamsize>::max()'\n');
 }
}