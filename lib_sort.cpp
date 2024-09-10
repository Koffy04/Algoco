#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Abrir el archivo "prueba3_ordenada.txt" para lectura
    ifstream file("prueba3_ordenada.txt");
    // Abrir el archivo "lista_libreria.txt" para escritura
    ofstream file2("lista_libreria.txt");

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1; // Terminar el programa con un código de error
    }

    int N;
    file >> N; // Leer la cantidad de números desde el archivo
    // Crear un array dinámico para almacenar los números
    int* arr = new int[N];

    // Leer los números del archivo y almacenarlos en el array
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
    file.close(); // Cerrar el archivo después de leer

    auto inicio = chrono::high_resolution_clock::now();
    sort(arr, arr + N); // Ordenar el array usando la función sort de la librería estándar
    for (int i = 0; i < N; i++) {
        file2 << arr[i] << endl; // Escribir los números ordenados en el archivo de salida
    }
    file2.close(); // Cerrar el archivo de salida

    // Medir el tiempo final y calcular la duración
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl; // Mostrar la duración del ordenamiento en segundos

    // Liberar la memoria asignada dinámicamente
    delete[] arr;

    return 0; // Indicar que el programa finalizó correctamente
}
