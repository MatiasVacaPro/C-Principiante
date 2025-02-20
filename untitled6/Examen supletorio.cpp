//Programa simulador de incendios
// Created by Nicole Vaca on 2/19/25.


#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <array>
#include <iomanip>

using namespace std;

void imprimir_cuadricula(const vector<vector<char> >& cuadricula, int i = 0);
bool hay_arboles_en_llamas(const vector<vector<char> >& cuadricula, int i = 0, int j = 0);
int contar_f_en_fila(const vector<char>& fila, int j = 0);
int encontrar_fila_max_f(const vector<vector<char> >& cuadricula, int i = 0, int max_actual = -1, int fila_max_actual = 0);
void procesar_cuadricula(const vector<vector<char> >& actual, vector<vector<char> >& siguiente, int i = 0, int j = 0);
void simular(vector<vector<char> > cuadricula, int paso = 0);
void leer_dimensiones(int& M, int& N);
vector<vector<char> > leer_estado_del_bosque(int M, int N);
void modificar_bosque(vector<vector<char> >& bosque);

void imprimir_cuadricula(const vector<vector<char> >& cuadricula, int i) {
    if (i >= cuadricula.size()) {
        return;
    }
    for (char c : cuadricula[i]) {
        cout << c;
    }
    cout << endl;
    imprimir_cuadricula(cuadricula, i + 1);
}

bool hay_arboles_en_llamas(const vector<vector<char> >& cuadricula, int i, int j) {
    int M = cuadricula.size();

    if (M == 0) return false;

    int N = cuadricula[0].size();

    if (i >= M) return false;
    if (j >= N) return hay_arboles_en_llamas(cuadricula, i + 1, 0);

    if (cuadricula[i][j] == 'F') return true;
    else return hay_arboles_en_llamas(cuadricula, i, j + 1);
}

int contar_f_en_fila(const vector<char>& fila, int j) {
    if (j >= fila.size()) return 0;
    return (fila[j] == 'F') + contar_f_en_fila(fila, j + 1);
}

int encontrar_fila_max_f(const vector<vector<char> >& cuadricula, int i, int max_actual, int fila_max_actual) {
    if (i >= cuadricula.size()) return fila_max_actual;

    int cantidad = contar_f_en_fila(cuadricula[i], 0);
    if (cantidad > max_actual) {
        max_actual = cantidad;
        fila_max_actual = i;
    }
    return encontrar_fila_max_f(cuadricula, i + 1, max_actual, fila_max_actual);
}

void procesar_cuadricula(const vector<vector<char> >& actual, vector<vector<char> >& siguiente, int i, int j) {
    int M = actual.size();
    if (M == 0) return;
    int N = actual[0].size();

    if (i >= M) return;
    if (j >= N) {
        procesar_cuadricula(actual, siguiente, i + 1, 0);
        return;
    }

    if (actual[i][j] == 'F') {
        siguiente[i][j] = 'X';
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        for (int d = 0; d < 4; ++d) {
            int ni = i + di[d];
            int nj = j + dj[d];
            if (ni >= 0 && ni < M && nj >= 0 && nj < N) {
                if (actual[ni][nj] == 'T') {
                    siguiente[ni][nj] = 'F';
                }
            }
        }
    }

    procesar_cuadricula(actual, siguiente, i, j + 1);
}

void simular(vector<vector<char> > cuadricula, int paso) {
    if (!hay_arboles_en_llamas(cuadricula, 0, 0)) {
        cout << "No hay mas árboles en llamas. La simulacion termina." << endl;
        return;
    }

    cout << "\nPaso " << paso << ":" << endl;
    imprimir_cuadricula(cuadricula);
    int fila_maxima = encontrar_fila_max_f(cuadricula, 0, -1, 0);
    cout << "Fila con mas incendios: " << fila_maxima + 1 << endl;

    vector<vector<char> > siguiente_cuadricula = cuadricula;
    procesar_cuadricula(cuadricula, siguiente_cuadricula, 0, 0);
    simular(siguiente_cuadricula, paso + 1);
}

void leer_dimensiones(int& M, int& N) {
    while (true) {
        cout << "Ingrese el número de filas (M): ";
        cin >> M;
        if (cin.fail() || M <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Ingrese un entero positivo." << endl;
        } else {
            break;
        }
    }

    while (true) {
        cout << "Ingrese el número de columnas (N): ";
        cin >> N;
        if (cin.fail() || N <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un entero positivo." << endl;
        } else {
            break;
        }
    }
}

vector<vector<char> > leer_estado_del_bosque(int M, int N) {
    vector<vector<char> > bosque(M, vector<char>(N));
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < M; ++i) {
        string fila;
        bool valida = false;
        while (!valida) {
            cout << "Ingrese la fila " << i + 1 << " (longitud " << N << "): ";
            getline(cin, fila);
            if (fila.size() != N) {
                cout << "La fila debe tener exactamente " << N << " caracteres. Intente de nuevo." << endl;
                continue;
            }
            valida = true;
            for (char c : fila) {
                if (c != 'T' && c != 'F' && c != '.' && c != 'X') {
                    valida = false;
                    cout << "Caracter invalido '" << c << "'. Caracteres validos: T, F, ., X. Intente de nuevo." << endl;
                    break;
                }
            }
        }

        for (int j = 0; j < N; ++j) {
            bosque[i][j] = fila[j];
        }
        //cout << "prueba" << bosque[i][j] << endl;
    }
    return bosque;
}

void modificar_bosque(vector<vector<char> >& bosque) {
    int M = bosque.size();
    if (M == 0) {
        cout << "El bosque no ha sido inicializado." << endl;
        return;
    }
    int N = bosque[0].size();

    int fila, columna;
    char nuevo;

    cout << "Ingrese la fila (1-" << M << "): ";
    cin >> fila;
    if (cin.fail() || fila < 1 || fila > M) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Fila invalida." << endl;
        return;
    }

    cout << "Ingrese la columna (1-" << N << "): ";
    cin >> columna;
    if (cin.fail() || columna < 1 || columna > N) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Columna invalida." << endl;
        return;
    }

    cout << "Ingrese el nuevo caracter (T, F, ., X): ";
    cin >> nuevo;
    if (nuevo != 'T' && nuevo != 'F' && nuevo != '.' && nuevo != 'X') {
        cout << "Carácter inválido." << endl;
        return;
    }

    bosque[fila - 1][columna - 1] = nuevo;
    cout << "Celda actualizada correctamente." << endl;
}

int main() {
    int M = 0, N = 0;
    vector<vector<char> > bosque;

    while (true) {
        cout << "\n=== MENÚ ===" << endl;
        cout << "1. Ingresar dimensiones del bosque" << endl;
        cout << "2. Ingresar estado inicial del bosque" << endl;
        cout << "3. Ejecutar simulación" << endl;
        cout << "4. Modificar estado del bosque" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                leer_dimensiones(M, N);
                break;
            case 2:
                if (M <= 0 || N <= 0) {
                    cout << "Primero ingrese las dimensiones (Opcion 1)." << endl;
                    break;
                }
                bosque = leer_estado_del_bosque(M, N);
                break;
            case 3:
                if (bosque.empty()) {
                    cout << "Primero ingrese el estado del bosque (Opcion 2)." << endl;
                    break;
                }
                simular(bosque, 0);
                break;
            case 4:
                modificar_bosque(bosque);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }

    return 0;
    cout <<"El programa a termiando";
}
