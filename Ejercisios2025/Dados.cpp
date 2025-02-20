//Programa que almacena la cantidad de de veces que ha aparecido una cara de un dado
// Created by Nicole Vaca on 1/13/25.
//version 1.0.0.0


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define CARA 7
using namespace std;

int main() {
  srand(static_cast<unsigned int>(time(nullptr))); //Semilla para generar numeros aleatorios
    int lanzamientos[CARA]={0};
// Definir 6000000 de lanzamientos de dados
for (int lance =1; lance <= 120000000;lance++) {
  size_t cara = rand()%6;
  lanzamientos[cara]++;

}
cout << "Cara" << setw(6) << "Frecuencia" << endl;
for (size_t i =1; i<=6;i++) {
  cout << i << setw(15) << lanzamientos[i] << endl;

}




  cout << "El programa ha terminado" << endl;;
  return 0;
}
