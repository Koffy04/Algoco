#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

int main() {
    // Crear un objeto de tipo ofstream para manejar la escritura en archivos
    ofstream file;
    // Abrir el archivo "prueba1.txt" para escritura
    file.open("prueba1.txt");

    // Configurar lo random
    unsigned seed = static_cast<unsigned>(time(0)); 
    mt19937 g(seed); 
    uniform_int_distribution<> distrib(100000, 10000000); 

    // Generar un número aleatorio en el rango que el ayudante desee.
    int valor = distrib(g);
    cout << "Número generado: " << valor << endl; // Mostrar el número para saber cuanto se genero en la terminal generado en l

    // Crear una lista dinámica con la cant de elementos
    int* lista = new int[valor]; // asignar memoria para la lista
    for(int i = 0; i < valor; i++)
        lista[i] = i; // Inicializar la lista con valores.
    
    //un random
    shuffle(lista, lista + valor, g);

    // Guardar el número de elementos y la lista en el archivo
    file << valor << endl; 
    for (int i = 0; i < valor; i++)
        file << lista[i] << endl; /

    delete[] lista;

    file.close();
    return 0; 
}
