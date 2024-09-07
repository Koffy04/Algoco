#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    file >> N;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        file >> valor;
        vec.push_back(valor);
    }
    file.close();
    auto inicio = chrono::high_resolution_clock::now();
    quickSort(vec,0,N-1);
    
    for(int i=0; i < N;i++){
        file2 << vec[i] << endl;
    }
    file2.close();
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl;
    return 0;
}