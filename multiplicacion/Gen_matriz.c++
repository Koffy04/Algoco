#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int filas = 950;
    int columnas = 950;
    string nombreArchivo = "matriz3.txt";
    int filas2 = 950;
    int columnas2 = 950;
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }

    srand(std::time(nullptr)); // Inicializa la semilla de números aleatorios
    archivo << filas << endl;
    archivo << columnas << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            int numeroAleatorio = std::rand() % 100; // Genera un número aleatorio entre 0 y 99
            archivo << numeroAleatorio;
            if (j < columnas - 1) {
                archivo << " ";
            }
        }
        archivo << "\n";
    }
    archivo << filas2 << endl;
    archivo << columnas2 << endl;
    for (int i = 0; i < filas2; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            int numeroAleatorio = rand() % 100; // Genera un número aleatorio entre 0 y 99
            archivo << numeroAleatorio;
            if (j < columnas - 1) {
                archivo << " ";
            }
        }
        archivo << "\n";
    }
    
    cout << "Matriz generada y guardada en " << nombreArchivo << endl;
}
