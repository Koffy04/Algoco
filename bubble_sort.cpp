
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
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    
    ifstream file("prueba2_ordenada.txt");
    ofstream file2("lista_bubble_ordenado.txt");
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    
    int N;
    file >> N; // Leer la cantidad de números

    // Crear un array dinámico para almacenar los números
    int* arr = new int[N];

    // Leer los números del archivo
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
    file.close();
    auto inicio = chrono::high_resolution_clock::now();
    bubbleSort(arr, N);
    for(int i=0; i < N;i++){
        file2 << arr[i] << endl;
    }
    file2.close();
    delete[] arr;
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl;
    return 0;
}