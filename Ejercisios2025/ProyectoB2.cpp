//
// Created by Nicole Vaca on 2/4/25.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un producto
struct Producto {
    string nombre;
    int cantidad;

    // Constructor para crear un producto
    Producto(string n, int c) : nombre(n), cantidad(c) {}
};

// Estructura para representar una estantería
struct Estanteria {
    vector<Producto> productos;

    // Función para agregar un producto a la estantería
    void agregarProducto(const Producto& p) {
        productos.push_back(p);
    }

    // Función para verificar si la estantería está vacía
    bool estaVacia() {
        return productos.empty();
    }

    // Función para obtener el total de productos en esta estantería
    int totalProductos() {
        int total = 0;
        for (auto& p : productos) {
            total += p.cantidad;
        }
        return total;
    }
};

// Estructura para representar una sección
struct Seccion {
    string nombre;
    vector<Estanteria> estanterias;

    // Constructor para crear una sección
    Seccion(string n) : nombre(n) {}

    // Función para agregar una estantería a la sección
    void agregarEstanteria(const Estanteria& e) {
        estanterias.push_back(e);
    }

    // Función para calcular el total de productos en esta sección
    int totalProductos() {
        int total = 0;
        for (auto& estanteria : estanterias) {
            total += estanteria.totalProductos();
        }
        return total;
    }
};

// Función para ordenar los productos por nombre alfabéticamente
void ordenarProductos(Estanteria& estanteria) {
    sort(estanteria.productos.begin(), estanteria.productos.end(),
         [](const Producto& a, const Producto& b) {
             return a.nombre < b.nombre;
         });
}

// Menú de opciones
void mostrarMenu() {
    cout << "Menu de opciones:" << endl;
    cout << "1. Agregar producto a estantería" << endl;
    cout << "2. Ver productos totales de la sección" << endl;
    cout << "3. Ver estanterías vacías" << endl;
    cout << "4. Ver la estantería con más productos" << endl;
    cout << "5. Ver la estantería con menos productos" << endl;
    cout << "6. Ordenar productos de una estantería" << endl;
    cout << "7. Salir" << endl;
}

// Función principal
int main() {
    vector<Seccion> secciones; // Vector para almacenar las secciones del almacén
    int opcion;
    string nombreProducto;
    int cantidadProducto, opcionSeccion;

    // Bucle principal del menú
    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Agregar producto a estantería
                cout << "Ingrese el nombre del producto: ";
                cin >> nombreProducto;
                cout << "Ingrese la cantidad de productos: ";
                cin >> cantidadProducto;

                Producto p(nombreProducto, cantidadProducto);

                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;

                if (opcionSeccion <= secciones.size()) {
                    cout << "Ingrese el número de la estantería: ";
                    int estanteriaNum;
                    cin >> estanteriaNum;

                    if (estanteriaNum <= secciones[opcionSeccion - 1].estanterias.size()) {
                        secciones[opcionSeccion - 1].estanterias[estanteriaNum - 1].agregarProducto(p);
                    } else {
                        cout << "Estantería no válida." << endl;
                    }
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 2: {
                // Ver productos totales de la sección
                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;
                if (opcionSeccion <= secciones.size()) {
                    cout << "Total de productos en la sección " << secciones[opcionSeccion - 1].nombre
                         << ": " << secciones[opcionSeccion - 1].totalProductos() << endl;
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 3: {
                // Ver estanterías vacías
                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;
                if (opcionSeccion <= secciones.size()) {
                    for (int i = 0; i < secciones[opcionSeccion - 1].estanterias.size(); ++i) {
                        if (secciones[opcionSeccion - 1].estanterias[i].estaVacia()) {
                            cout << "Estantería " << i + 1 << " está vacía." << endl;
                        }
                    }
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 4: {
                // Ver la estantería con más productos
                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;
                if (opcionSeccion <= secciones.size()) {
                    int maxProductos = -1;
                    int estanteriaMax = -1;
                    for (int i = 0; i < secciones[opcionSeccion - 1].estanterias.size(); ++i) {
                        int total = secciones[opcionSeccion - 1].estanterias[i].totalProductos();
                        if (total > maxProductos) {
                            maxProductos = total;
                            estanteriaMax = i;
                        }
                    }
                    cout << "La estantería con más productos es la " << estanteriaMax + 1 << endl;
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 5: {
                // Ver la estantería con menos productos
                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;
                if (opcionSeccion <= secciones.size()) {
                    int minProductos = INT_MAX;
                    int estanteriaMin = -1;
                    for (int i = 0; i < secciones[opcionSeccion - 1].estanterias.size(); ++i) {
                        int total = secciones[opcionSeccion - 1].estanterias[i].totalProductos();
                        if (total < minProductos) {
                            minProductos = total;
                            estanteriaMin = i;
                        }
                    }
                    cout << "La estantería con menos productos es la " << estanteriaMin + 1 << endl;
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 6: {
                // Ordenar productos de una estantería
                cout << "Ingrese el número de la sección (1, 2, ...): ";
                cin >> opcionSeccion;
                if (opcionSeccion <= secciones.size()) {
                    cout << "Ingrese el número de la estantería: ";
                    int estanteriaNum;
                    cin >> estanteriaNum;

                    if (estanteriaNum <= secciones[opcionSeccion - 1].estanterias.size()) {
                        ordenarProductos(secciones[opcionSeccion - 1].estanterias[estanteriaNum - 1]);
                        cout << "Productos ordenados alfabéticamente." << endl;
                    } else {
                        cout << "Estantería no válida." << endl;
                    }
                } else {
                    cout << "Sección no válida." << endl;
                }
                break;
            }
            case 7:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }

    } while (opcion != 7);

    return 0;
}

