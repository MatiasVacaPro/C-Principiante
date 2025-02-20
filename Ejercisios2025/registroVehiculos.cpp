// Programa que define el refgistro de cehiculos para su estacionamito
// Created by Nicole Vaca on 1/23/25.
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Definicion de estructuras
struct Vehiculo {
    string placa;
    string modelo;
    int horaEntrada;
};

// Definicion de funciones
void registrarVehiculo(vector<Vehiculo>&);
void mostrarVehiculo(const vector<Vehiculo>&);
void eliminarVehiculo(vector<Vehiculo>&);

int main() {
    vector<Vehiculo> vehiculos;
    int opcion;

    cout << "Estacionamiento Pepito\n";

    do {
        cout << "1. Registrar Vehiculo\n";
        cout << "2. Mostrar vehiculos en estacionamiento\n";
        cout << "3. Sacar vehiculo\n";
        cout << "4. Salir\n";
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarVehiculo(vehiculos);
                break;
            case 2:
                mostrarVehiculo(vehiculos);
                break;
            case 3:
                eliminarVehiculo(vehiculos);
                break;
            case 4:
                cout << "Gracias por usar nuestro estacionamiento\n";
                break;
            default:
                cout << "Opcion invalida, ingrese una opcion valida\n";
        }
    } while (opcion != 4);

    return 0;
}

void registrarVehiculo(vector<Vehiculo>& vehiculos) {
    Vehiculo nuevoVehiculo;

    try {
        // Ingreso de la placa y validacion de caracteres
        cout << "Ingrese la placa del vehiculo (6 caracteres sin guion): ";
        cin >> nuevoVehiculo.placa;
        if (nuevoVehiculo.placa.length() != 6) {
            throw runtime_error("La placa debe tener necesariamente 6 caracteres");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Ingrese el modelo por teclado
        cout << "Ingrese el modelo del vehiculo: ";
        getline(cin, nuevoVehiculo.modelo);

        // Ingreso de la hora de entrada por teclado
        cout << "Ingrese la hora de entrada del vehiculo (formato 24 horas): ";
        cin >> nuevoVehiculo.horaEntrada;
        if (nuevoVehiculo.horaEntrada < 0 || nuevoVehiculo.horaEntrada > 23) {
            throw runtime_error("La hora de entrada debe estar entre 0 y 23");
        }

        // Agregar el vehiculo al vector
        vehiculos.push_back(nuevoVehiculo);
        cout << "Vehiculo registrado correctamente\n";

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << "\n";
    } catch (...) { // Captura de excepciones desconocidas
        cout << "Error desconocido en el ingreso del vehiculo.\n";
    }
}

void mostrarVehiculo(const vector<Vehiculo>& vehiculos) {
    if (vehiculos.empty()) {
        cout << "No hay vehiculos registrados.\n";
        return;
    }

    cout << "Vehiculos registrados en el estacionamiento:\n";
    for (const auto& v : vehiculos) {
        cout << "Placa: " << v.placa << "\nModelo: " << v.modelo
             << "\nHora de ingreso: " << v.horaEntrada << ":00\n\n";
    }
}

void eliminarVehiculo(vector<Vehiculo>& vehiculos) {
    string placaVehiculo;
    cout << "Ingrese la placa del vehiculo que desea eliminar: ";
    cin >> placaVehiculo;

    for (auto i = vehiculos.begin(); i != vehiculos.end(); ++i) {
        if (i->placa == placaVehiculo) {
            vehiculos.erase(i);
            cout << "Vehiculo con placa " << placaVehiculo << " salio del estacionamiento.\n";
            return;
        }
    }

    cout << "Vehiculo con placa " << placaVehiculo << " no encontrado.\n";
}
