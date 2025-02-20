
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
    cout << "El porcentaje de ocupación es: ";
