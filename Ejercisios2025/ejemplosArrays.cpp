//
// Created by Nicole Vaca on 1/22/25.
//
// Example 1: Simple Array Declaration and Initialization
#include <iostream>
#include <array>
using namespace std;

int main() {
    int numeros [9]= {1,2,3,4,5,6,7,8,9};
    cout << "Array original: ";
    for(int i = 0;i < 9;i++){
        cout << i << " ";
    }
    cout <<"\n";

    int suma = 10;
    for (int i : numeros) {
        i += suma;
        cout << i << " ";
    }

    cout << "Con satisfacción";
    return 0;
}

void ejemplo() {
    int matrix[3][4]={
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}

    };
}