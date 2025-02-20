#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Estructura para representar un producto
struct Producto {
    string nombre;
    int cantidad;

    Producto(string nombre, int cantidad) : nombre(nombre), cantidad(cantidad) {}
};

// Estructura para representar una estantería
struct Estanteria {
    string nombre;  // Agregamos un nombre para la estantería
    vector<Producto> productos;  // Arreglo dinámico de productos

    // Función para agregar un producto a la estantería
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
    }

    // Función para verificar si la estantería está vacía
    bool estaVacia() const {
        return productos.empty();
    }

    // Función para obtener el total de productos en la estantería
    int obtenerTotalProductos() const {
        int total = 0;
        for (const auto& producto : productos) {
            total += producto.cantidad;
        }
        return total;
    }

    // Función para ordenar los productos de la estantería alfabéticamente
    void ordenarProductos() {
        sort(productos.begin(), productos.end(), [](const Producto& a, const Producto& b) {
            return a.nombre < b.nombre;
        });
    }
};

// Estructura para representar una sección en el almacén
struct Seccion {
    string nombre;
    vector<Estanteria> estanterias;

    // Función para agregar una estantería a la sección
    void agregarEstanteria(const Estanteria& estanteria) {
        estanterias.push_back(estanteria);
    }

    // Función para obtener el total de productos de todas las estanterías en la sección
    int obtenerTotalProductos() const {
        int total = 0;
        for (const auto& estanteria : estanterias) {
            total += estanteria.obtenerTotalProductos();
        }
        return total;
    }

    // Función para encontrar la estantería con más y menos productos
    void obtenerEstanteriaMasYMenosProductos() const {
        if (estanterias.empty()) {
            cout << "No hay estanterías en esta sección." << endl;
            return;
        }

        const Estanteria* estanteriaMasProductos = &estanterias[0];
        const Estanteria* estanteriaMenosProductos = &estanterias[0];

        for (const auto& estanteria : estanterias) {
            if (estanteria.obtenerTotalProductos() > estanteriaMasProductos->obtenerTotalProductos()) {
                estanteriaMasProductos = &estanteria;
            }
            if (estanteria.obtenerTotalProductos() < estanteriaMenosProductos->obtenerTotalProductos()) {
                estanteriaMenosProductos = &estanteria;
            }
        }

        cout << "Estantería con más productos: " << estanteriaMasProductos->obtenerTotalProductos() << " productos" << endl;
        cout << "Estantería con menos productos: " << estanteriaMenosProductos->obtenerTotalProductos() << " productos" << endl;
    }
};

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\nMenu de opciones:" << endl;
    cout << "1. Agregar producto a estantería" << endl;
    cout << "2. Verificar si una estantería está vacía" << endl;
    cout << "3. Ver total de productos en una sección" << endl;
    cout << "4. Ver estantería con más y menos productos" << endl;
    cout << "5. Ordenar productos en estantería" << endl;
    cout << "6. Salir" << endl;
}

// Función para mostrar las secciones y las estanterías disponibles
void mostrarSeccionesYEstanterias(const vector<Seccion>& secciones) {
    if (secciones.empty()) {
        cout << "No hay secciones disponibles." << endl;
        return;
    }

    cout << "\nSecciones disponibles:" << endl;
    for (size_t i = 0; i < secciones.size(); ++i) {
        cout << i + 1 << ". " << secciones[i].nombre << endl;
        cout << "   Estanterías disponibles:" << endl;
        for (size_t j = 0; j < secciones[i].estanterias.size(); ++j) {
            cout << "      - " << secciones[i].estanterias[j].nombre << endl;
        }
    }
}

int main() {
    // Creamos productos predefinidos para la papelería
    Producto p1("Lápiz", 100);
    Producto p2("Borrador", 50);
    Producto p3("Cuaderno", 30);
    Producto p4("Regla", 20);
    Producto p5("Tijeras", 10);

    // Creamos estanterías con algunos productos
    Estanteria estanteria1{"Estantería A"};
    estanteria1.agregarProducto(p1);
    estanteria1.agregarProducto(p2);
    estanteria1.agregarProducto(p3);

    Estanteria estanteria2{"Estantería B"};
    estanteria2.agregarProducto(p4);
    estanteria2.agregarProducto(p5);

    // Creamos secciones y les agregamos estanterías
    Seccion seccion1{"Papelería Principal"};
    seccion1.agregarEstanteria(estanteria1);
    seccion1.agregarEstanteria(estanteria2);

    // Lista de secciones (almacén)
    vector<Seccion> secciones;
    secciones.push_back(seccion1);

    int opcion;
    do {
        mostrarSeccionesYEstanterias(secciones);  // Mostrar secciones y estanterías
        mostrarMenu();
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cin.ignore();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                // Agregar producto a estantería
                string nombreSeccion, nombreEstanteria, nombreProducto;
                int cantidadProducto;

                cout << "Ingrese nombre de la sección: ";
                getline(cin, nombreSeccion);
                cout << "Ingrese nombre de la estantería: ";
                getline(cin, nombreEstanteria);
                cout << "Ingrese nombre del producto: ";
                getline(cin, nombreProducto);
                cout << "Ingrese cantidad del producto: ";
                cin >> cantidadProducto;
                cin.ignore();

                // Buscar la sección y estantería
                Seccion* seccionEncontrada = nullptr;
                Estanteria* estanteriaEncontrada = nullptr;

                for (auto& seccion : secciones) {
                    if (seccion.nombre == nombreSeccion) {
                        seccionEncontrada = &seccion;
                        for (auto& estanteria : seccion.estanterias) {
                            if (estanteria.nombre == nombreEstanteria) {
                                estanteriaEncontrada = &estanteria;
                                break;
                            }
                        }
                        break;
                    }
                }

                if (seccionEncontrada && estanteriaEncontrada) {
                    Producto producto(nombreProducto, cantidadProducto);
                    estanteriaEncontrada->agregarProducto(producto);
                    cout << "Producto agregado correctamente." << endl;
                } else {
                    cout << "Sección o estantería no encontrada." << endl;
                }
                break;
            }

            case 2: {
                // Verificar si una estantería está vacía
                string nombreSeccion, nombreEstanteria;
                cout << "Ingrese nombre de la sección: ";
                getline(cin, nombreSeccion);
                cout << "Ingrese nombre de la estantería: ";
                getline(cin, nombreEstanteria);

                // Buscar la sección y estantería
                Seccion* seccionEncontrada = nullptr;
                Estanteria* estanteriaEncontrada = nullptr;

                for (auto& seccion : secciones) {
                    if (seccion.nombre == nombreSeccion) {
                        seccionEncontrada = &seccion;
                        for (auto& estanteria : seccion.estanterias) {
                            if (estanteria.nombre == nombreEstanteria) {
                                estanteriaEncontrada = &estanteria;
                                break;
                            }
                        }
                        break;
                    }
                }

                if (seccionEncontrada && estanteriaEncontrada) {
                    if (estanteriaEncontrada->estaVacia()) {
                        cout << "La estantería está vacía." << endl;
                    } else {
                        cout << "La estantería tiene productos." << endl;
                    }
                } else {
                    cout << "Sección o estantería no encontrada." << endl;
                }
                break;
            }

            case 3: {
                // Ver total de productos en una sección
                string nombreSeccion;
                cout << "Ingrese nombre de la sección: ";
                getline(cin, nombreSeccion);

                Seccion* seccionEncontrada = nullptr;
                for (auto& seccion : secciones) {
                    if (seccion.nombre == nombreSeccion) {
                        seccionEncontrada = &seccion;
                        break;
                    }
                }

                if (seccionEncontrada) {
                    cout << "Total de productos en la sección: " << seccionEncontrada->obtenerTotalProductos() << endl;
                } else {
                    cout << "Sección no encontrada." << endl;
                }
                break;
            }

            case 4: {
                // Ver estantería con más y menos productos
                string nombreSeccion;
                cout << "Ingrese nombre de la sección: ";
                getline(cin, nombreSeccion);

                Seccion* seccionEncontrada = nullptr;
                for (auto& seccion : secciones) {
                    if (seccion.nombre == nombreSeccion) {
                        seccionEncontrada = &seccion;
                        break;
                    }
                }

                if (seccionEncontrada) {
                    seccionEncontrada->obtenerEstanteriaMasYMenosProductos();
                } else {
                    cout << "Sección no encontrada." << endl;
                }
                break;
            }

            case 5: {
                // Ordenar productos en estantería
                string nombreSeccion, nombreEstanteria;
                cout << "Ingrese nombre de la sección: ";
                getline(cin, nombreSeccion);
                cout << "Ingrese nombre de la estantería: ";
                getline(cin, nombreEstanteria);

                Seccion* seccionEncontrada = nullptr;
                Estanteria* estanteriaEncontrada = nullptr;

                for (auto& seccion : secciones) {
                    if (seccion.nombre == nombreSeccion) {
                        seccionEncontrada = &seccion;
                        for (auto& estanteria : seccion.estanterias) {
                            if (estanteria.nombre == nombreEstanteria) {
                                estanteriaEncontrada = &estanteria;
                                break;
                            }
                        }
                        break;
                    }
                }

                if (seccionEncontrada && estanteriaEncontrada) {
                    estanteriaEncontrada->ordenarProductos();
                    cout << "Productos ordenados alfabéticamente." << endl;
                } else {
                    cout << "Sección o estantería no encontrada." << endl;
                }
                break;
            }

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 6);

    return 0;
}
