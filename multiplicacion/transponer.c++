#include <bits/stdc++.h>
using namespace std;

// Función para multiplicar A * B^T
vector<vector<int>> transpuesta(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int m = A.size();       // Filas de A
    int n = A[0].size();    // Columnas de A (y filas de B)
    int p = B.size();       // Filas de B (columnas de B transpuesta)

    // Crear la matriz resultante de tamaño m x p e inicializarla con ceros
    vector<vector<int>> C(m, vector<int>(p, 0));

    // Realizar la multiplicación de A con B^T
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[j][k]; // B[j][k] es equivalente a B^T[k][j]
            }
        }
    }

    return C;
}

int main() {
    ifstream file("matriz3.txt");
    ofstream file2("transpuesta.txt");
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    
    int filas, columnas, filas2, columnas2;

    // Leer filas y columnas de la primera matriz
    file >> filas >> columnas;
    vector<vector<int>> arreglo(filas, vector<int>(columnas));  // Inicializar con las dimensiones correctas
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            file >> arreglo[i][j];
        }
    }

    // Leer filas y columnas de la segunda matriz
    file >> filas2 >> columnas2;
    
    vector<vector<int>> arreglo2(filas2, vector<int>(columnas2));  // Inicializar con las dimensiones correctas
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas2; j++) {
            file >> arreglo2[i][j];
        }
    }
    // Verificar que las matrices sean multiplicables
    if (columnas != filas2) {
        cerr << "Las matrices no son multiplicables: el número de columnas de la primera matriz no coincide con el número de filas de la segunda matriz." << endl;
        return 1;
    }
    else{
        auto inicio = chrono::high_resolution_clock::now();
        vector<vector<int>> resultado= transpuesta(arreglo, arreglo2);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "el tiempo es" << duracion.count() << " microsegundos"<< endl;
        for (int i = 0; i < filas2; i++) {
            for (int j = 0; j < columnas2; j++) {
                file2 << resultado[i][j] << " ";
            }
            file2 << "\n";
        }
        file.close();
        file2.close();
    }
    return 0;
}