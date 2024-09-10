// C++ program for implementation 
// of Bubble sort
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;

// Funcion bubble sort de ordenamiento
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]); // Intercambiar elementos si están en el orden incorrecto
            }
        }
    }
}
//Consiste en intercambiar numeros si el j-esimo elemento es mayor al j-esimo + 1
int main() {
    // Para cambiar 
    ifstream file("prueba2_ordenada.txt");
    // Abrir el archivo "lista_bubble_ordenado.txt" para escritura
    ofstream file2("lista_bubble_ordenado.txt");

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

    // Medir el tiempo de ejecución del algoritmo de ordenamiento
    auto inicio = chrono::high_resolution_clock::now();
    bubbleSort(arr, N); // Ordenar el array usando Bubble Sort
    for(int i = 0; i < N; i++) {
        file2 << arr[i] << endl; // Escribir los números ordenados en el archivo de salida
    }
    file2.close(); // Cerrar el archivo de salida

    // Liberar la memoria asignada dinámicamente
    delete[] arr;

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl; // Mostrar la duración del ordenamiento en ms

    return 0; // Indicar que el programa finalizó correctamente
}
