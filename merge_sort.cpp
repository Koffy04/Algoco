#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> // Incluye muchas bibliotecas estándar (no recomendado en código de producción)
using namespace std;

// Función para combinar dos sub-arreglos ordenados en un solo arreglo ordenado
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del primer sub-arreglo la mitad izquierda
    int n2 = right - mid;    // Tamaño del segundo sub-arreglo, la mitad derecha

    // Crear vectores para los dos sub-arreglos
    vector<int> L(n1), R(n2);

    // Copiar datos a los sub-arreglos L y R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // Índices para recorrer L y R
    int k = left;     // Índice para recorrer el arreglo principal

    // Combinar los sub-arreglos L y R en arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L, si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función para ordenar el arreglo usando Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return; // Casos base: el arreglo tiene un solo elemento o está vacío

    int mid = left + (right - left) / 2; // Encontrar el punto medio

    // Ordenar las dos mitades del arreglo
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combinar las dos mitades ordenadas
    merge(arr, left, mid, right);
}

int main() {
    // Abrir el archivo "prueba1_ordenada.txt" para lectura
    ifstream file("prueba1_ordenada.txt");
    // Abrir el archivo "lista_merge.txt" para escritura
    ofstream file2("lista_merge.txt");

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1; // Terminar el programa con un código de error
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

    // Medir el tiempo de ejecución del algoritmo de ordenamiento
    auto inicio = chrono::high_resolution_clock::now();
    mergeSort(vec, 0, N - 1); // Ordenar el vector usando Merge Sort
    
    for (int i = 0; i < N; i++) {
        file2 << vec[i] << endl; // Escribir los números ordenados en el archivo de salida
    }
    file2.close(); // Cerrar el archivo de salida

    // Medir el tiempo final y calcular la duración
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl; // Mostrar la duración del ordenamiento en segundos

    return 0; // Indicar que el programa finalizó correctamente
}
