#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;

// Definir la estructura de un espacio en el estacionamiento
struct Espacio {
    char estado;  // 'L' = Libre, 'R' = Reservado, 'O' = Ocupado
    string horaEntrada;
    string horaSalida;
};

// Definir las dimensiones del estacionamiento
const int FILAS = 8;
const int COLUMNAS = 12;
Espacio estacionamiento[FILAS][COLUMNAS];

// Función para inicializar el estacionamiento
void inicializarEstacionamiento() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            estacionamiento[i][j].estado = 'L';  // Todos los espacios empiezan como libres
            estacionamiento[i][j].horaEntrada = "";
            estacionamiento[i][j].horaSalida = "";
        }
    }
}

// Función para mostrar el estado del estacionamiento
void mostrarEstado() {
    cout << "\nEstado del Estacionamiento:\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "[" << estacionamiento[i][j].estado << "] ";
        }
        cout << endl;
    }
}

// Función para reservar un espacio
void reservarEspacio() {
    int fila, columna;
    string horaEntrada, horaSalida;

    try {
        cout << "Ingrese la fila (0-7): ";
        cin >> fila;
        if (fila < 0 || fila >= FILAS) {
            throw out_of_range("Fila fuera de rango.");
        }

        cout << "Ingrese la columna (0-11): ";
        cin >> columna;
        if (columna < 0 || columna >= COLUMNAS) {
            throw out_of_range("Columna fuera de rango.");
        }

        if (estacionamiento[fila][columna].estado == 'O') {
            throw runtime_error("Este espacio ya está ocupado.");
        }

        cout << "Ingrese la hora de entrada (formato HH:MM): ";
        cin.ignore();  // Limpiar el buffer de entrada
        getline(cin, horaEntrada);

        cout << "Ingrese la hora de salida (formato HH:MM): ";
        getline(cin, horaSalida);

        // Asignar los valores al espacio
        estacionamiento[fila][columna].estado = 'R';
        estacionamiento[fila][columna].horaEntrada = horaEntrada;
        estacionamiento[fila][columna].horaSalida = horaSalida;

        cout << "¡Reserva realizada con éxito!\n";
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "Ocurrió un error inesperado.\n";
    }
}

// Función para liberar un espacio
void liberarEspacio() {
    int fila, columna;

    try {
        cout << "Ingrese la fila (0-7): ";
        cin >> fila;
        if (fila < 0 || fila >= FILAS) {
            throw out_of_range("Fila fuera de rango.");
        }

        cout << "Ingrese la columna (0-11): ";
        cin >> columna;
        if (columna < 0 || columna >= COLUMNAS) {
            throw out_of_range("Columna fuera de rango.");
        }

        if (estacionamiento[fila][columna].estado == 'L') {
            throw runtime_error("Este espacio ya está libre.");
        }

        // Liberar el espacio
        estacionamiento[fila][columna].estado = 'L';
        estacionamiento[fila][columna].horaEntrada = "";
        estacionamiento[fila][columna].horaSalida = "";

        cout << "¡Espacio liberado con éxito!\n";
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    } catch (...) {
        cout << "Ocurrió un error inesperado.\n";
    }
}

// Función para calcular el porcentaje de ocupación
void calcularOcupacion() {
    int totalEspacios = FILAS * COLUMNAS;
    int ocupados = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (estacionamiento[i][j].estado == 'O') {
                ocupados++;
            }
        }
    }

    double porcentaje = (ocupados * 100.0) / totalEspacios;
    cout << "El porcentaje de ocupación es: " << fixed << setprecision(2) << porcentaje << "%\n";
}

// Función para encontrar la fila con más espacios ocupados
void filaMasOcupada() {
    int maxOcupados = 0;
    int filaMax = 0;

    for (int i = 0; i < FILAS; i++) {
        int ocupadosEnFila = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            if (estacionamiento[i][j].estado == 'O') {
                ocupadosEnFila++;
            }
        }

        if (ocupadosEnFila > maxOcupados) {
            maxOcupados = ocupadosEnFila;
            filaMax = i;
        }
    }

    cout << "La fila con más espacios ocupados es la fila " << filaMax << " con " << maxOcupados << " espacios ocupados.\n";
}

// Función para mostrar el menú y manejar las opciones
void mostrarMenu() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Mostrar estado del estacionamiento\n";
        cout << "2. Reservar un espacio\n";
        cout << "3. Liberar un espacio\n";
        cout << "4. Calcular porcentaje de ocupación\n";
        cout << "5. Ver fila más ocupada\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEstado();
                break;
            case 2:
                reservarEspacio();
                break;
            case 3:
                liberarEspacio();
                break;
            case 4:
                calcularOcupacion();
                break;
            case 5:
                filaMasOcupada();
                break;
            case 6:
                cout << "Gracias por usar el sistema. ¡Hasta pronto!\n";
                break;
            default:
                cout << "Opción no válida, intente nuevamente.\n";
        }
    } while (opcion != 6);
}

int main() {
    inicializarEstacionamiento();
    mostrarMenu();
    return 0;
}
