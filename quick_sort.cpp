#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;

// Función para particionar el arreglo y elegir el pivote
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegir el último elemento como pivote
    int i = low - 1;       // Índice del elemento más pequeño

    // Reordenar los elementos para que los menores al pivote estén a la izquierda y los mayores a la derecha
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // intercambiar los elementos en el apartado de la particion
        }
    }
    swap(arr[i + 1], arr[high]); // Colocar el pivote en su posición correcta
    return i + 1; // Devolver el índice del pivote
}

// Función para ordenar el arreglo usando el algoritmo Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Particionar el arreglo
        quickSort(arr, low, pi - 1); // Ordenar la parte izquierda
        quickSort(arr, pi + 1, high); // Ordenar la parte derecha
    }
}

int main() {
    ifstream file("prueba3_ordenada.txt");
    ofstream file2("lista_quick.txt");

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1; 
    }

    int N, valor;
    file >> N; // Leer la cantidad de números desde el archivo

    // Crear un vector para almacenar los números
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        file >> valor;
        vec.push_back(valor); // Añadir cada número al vector
    }
    file.close(); // Cerrar el archivo después de leer

    auto inicio = chrono::high_resolution_clock::now();
    quickSort(vec, 0, N - 1); // Ordenar el vector usando Quick Sort
    
    for (int i = 0; i < N; i++) {
        file2 << vec[i] << endl; // Escribir los números ordenados en el archivo de salida
    }
    file2.close(); // Cerrar el archivo de salida

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl; // Mostrar la duración del ordenamiento en segundos

    return 0;
}
