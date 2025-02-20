#include <iostream>
#include <iomanip>
#include <string>
#include <array>
using namespace std;


struct Espacio {
    char estado;
};

// Dimensione
const int FILAS = 8;
const int COLUMNAS = 12;
Espacio estacionamiento[FILAS][COLUMNAS];

// Espacios
void inicializarEstacionamiento() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            estacionamiento[i][j].estado = 'L';  // Todos los espacios empiezan como libres
        }
    }
}

// Mostrar estado del estacionamiento
void mostrarEstado() {
    cout << "\nEstado del Estacionamiento:\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "[" << estacionamiento[i][j].estado << "] ";
        }
        cout << endl;
    }
}

// Reservar un espacio
void reservarEspacio() {
    int fila, columna;

    cout << "Ingrese la fila (0-7): ";
    cin >> fila;
    cout << "Ingrese la columna (0-11): ";
    cin >> columna;

    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
        if (estacionamiento[fila][columna].estado == 'L') {
            estacionamiento[fila][columna].estado = 'R';
            cout << "¡Reserva realizada con éxito!\n";
        } else {
            cout << "Este espacio no está disponible para reserva.\n";
        }
    } else {
        cout << "¡Fila o columna fuera de rango! Intente de nuevo.\n";
    }
}

// Liberar un espacio
void liberarEspacio() {
    int fila, columna;

    cout << "Ingrese la fila (0-7): ";
    cin >> fila;
    cout << "Ingrese la columna (0-11): ";
    cin >> columna;

    if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS) {
        if (estacionamiento[fila][columna].estado == 'R') {
            estacionamiento[fila][columna].estado = 'L';  //
            cout << "¡Espacio liberado con éxito!\n";
        } else {
            cout << "Este espacio no está reservado para liberar.\n";
        }
    } else {
        cout << "¡Fila o columna fuera de rango! Intente de nuevo.\n";
    }
}

// POorcentaje de ocupación
void calcularOcupacion() {
    int totalEspacios = FILAS * COLUMNAS;
    int ocupados = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (estacionamiento[i][j].estado == 'R' || estacionamiento[i][j].estado == 'O') {
                ocupados++;  // Se cuenta como ocupado si está reservado o ocupado
            }
        }
    }

    double porcentaje = (ocupados * 100.0) / totalEspacios;
    cout << "El porcentaje de ocupación es: " << fixed << setprecision(2) << porcentaje << "%\n";
}

// Ffila kmas ocupada
void filaMasOcupada() {
    int maxOcupados = 0;
    int filaMax = 0;

    for (int i = 0; i < FILAS; i++) {
        int ocupadosEnFila = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            if (estacionamiento[i][j].estado == 'R' || estacionamiento[i][j].estado == 'O') {
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

//Menu
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
