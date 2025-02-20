//
// Created by Nicole Vaca on 2/19/25.
//
#include <iostream>
using namespace std;

int main(){

    int transportes[3][5] = {
        {5, 7, 3, 4, 2},//Quito
        {10, 2, 5, 4, 5},//Guayaquil
        {2, 4, 7, 8, 5},//Cuenca

    };
    //Menu
    int opcion;
    do {

        cout << "\n\nMenú:\n";
        cout << "1.  Imprimir el transportes.\n";
        cout << "2   Agregar transporte.\n";
        cout << "3. Salir.\n";

        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                for(int i = 0;i<3;i++) {
                    for (int j=0;j<5;j++) {
                        cout << transportes[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            case 2:
                cout << "Para modificar el nuero ingrese.\n";
                cout << "Fila : ";
                int fila;
                cin >> fila;
                cout << "Columna : ";
                int columna;
                cin >> columna;
                break;
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    }while (opcion !=3);
    return 0;

}
