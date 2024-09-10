
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
int main() {
    ofstream file;
    file.open("prueba2_ordenada.txt");

    // Configurar generador de random
    unsigned seed = static_cast<unsigned>(time(0));
    mt19937 g(seed);
    uniform_int_distribution<> distrib(10000, 1000000);

    // Generar un número aleatorio entre el rango que desee el ayudante
    int valor = distrib(g);
    cout << "Número generado: " << valor << endl;

    // Crear una lista con 'valor' elementos
    int* lista = new int[valor];
    for(int i = 0; i < valor; i++)
        lista[i] = i;
    // Guardar el valor y la lista en el archivo
    file << valor << endl;
    for (int i = 0; i < valor; i++)
        file << lista[i] << endl;

    // la diferencia es que antes no hay un shuffle
    delete[] lista;

    file.close();
    return 0;
}
