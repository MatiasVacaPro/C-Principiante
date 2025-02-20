#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void imprimir_cuadricula(const vector<vector<char> >& cuadricula) {
    for (const auto& fila : cuadricula) {
        for (char c : fila) {
            cout << c;
        }
        cout << endl;
    }
}

bool hay_arboles_en_llamas(const vector<vector<char> >& cuadricula) {
    for (const auto& fila : cuadricula) {
        for (char c : fila) {
            if (c == 'F') return true;
        }
    }
    return false;
}

void procesar_cuadricula(vector<vector<char> >& cuadricula) {
    int M = cuadricula.size();
    int N = cuadricula[0].size();
    vector<vector<char> > siguiente_cuadricula = cuadricula;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (cuadricula[i][j] == 'F') {
                siguiente_cuadricula[i][j] = 'X';  // Marca el árbol como quemado
                // Propaga el fuego a los vecinos
                if (i > 0 && cuadricula[i-1][j] == 'T') siguiente_cuadricula[i-1][j] = 'F'; // Arriba
                if (i < M-1 && cuadricula[i+1][j] == 'T') siguiente_cuadricula[i+1][j] = 'F'; // Abajo
                if (j > 0 && cuadricula[i][j-1] == 'T') siguiente_cuadricula[i][j-1] = 'F'; // Izquierda
                if (j < N-1 && cuadricula[i][j+1] == 'T') siguiente_cuadricula[i][j+1] = 'F'; // Derecha
            }
        }
    }

    cuadricula = siguiente_cuadricula;
}

void simular(vector<vector<char> > cuadricula, int paso) {
    if (!hay_arboles_en_llamas(cuadricula)) {
        cout << "No hay más árboles en llamas. La simulación termina." << endl;
        return;
    }

    cout << "\nPaso " << paso << ":" << endl;
    imprimir_cuadricula(cuadricula);

    procesar_cuadricula(cuadricula);
    simular(cuadricula, paso + 1);
}

int main() {
    int M, N;
    cout << "Ingrese el número de filas (M): ";
    cin >> M;
    cout << "Ingrese el número de columnas (N): ";
    cin >> N;

    vector<vector<char> > bosque(M, vector<char>(N));

    cout << "Ingrese el estado inicial del bosque (T = árbol, F = fuego, . = vacío):" << endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> bosque[i][j];
        }
    }

    simular(bosque, 0);

    return 0;
}
