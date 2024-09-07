#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;
int main(){
    
    ifstream file("prueba3_ordenada.txt");
    ofstream file2("lista_libreria.txt");
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    int N;
    file >> N;
    int* arr = new int[N];

    // Leer los números del archivo
    for (int i = 0; i < N; i++) {
        file >> arr[i];
    }
    file.close();
    auto inicio = chrono::high_resolution_clock::now();
    sort(arr, arr+N);
    
    for(int i=0; i < N;i++){
        file2 << arr[i] << endl;
    }
    file2.close();
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl;

    delete[] arr;

}