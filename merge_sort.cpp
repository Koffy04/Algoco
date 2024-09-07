
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;
void merge(vector<int>& arr, int left,int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0;
    int k = left;
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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    
    ifstream file("prueba1_ordenada.txt");
    ofstream file2("lista_merge.txt");
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
    mergeSort(vec,0,N-1);
    
    for(int i=0; i < N;i++){
        file2 << vec[i] << endl;
    }
    file2.close();
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    cout << "Duracion: " << duracion.count() << " segundos" << endl;
    return 0;
}