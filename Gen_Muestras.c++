
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
int main() {
    ofstream file;
    file.open("prueba1.txt");

    // Configurar generador de números aleatorios
    unsigned seed = static_cast<unsigned>(time(0));
    mt19937 g(seed);
    uniform_int_distribution<> distrib(100000, 10000000);

    // Generar un número aleatorio entre 10,000 y 10^8
    int valor = distrib(g);
    cout << "Número generado: " << valor << endl;

    // Crear una lista con 'valor' elementos
    int* lista = new int[valor];
    for(int i = 0; i < valor; i++)
        lista[i] = i;
    shuffle(lista, lista + valor, g);
    // Guardar el valor y la lista en el archivo
    file << valor << endl;
    for (int i = 0; i < valor; i++)
        file << lista[i] << endl;

    // Liberar la memoria asignada dinámicamente
    delete[] lista;

    file.close();
    return 0;
}
