#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2, int fila, int columna, int columna2)
{
    vector<vector<int>> rslt(fila, vector<int>(columna2, 0));

    cout << "Multiplication of given two matrices is:\n";

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna2; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < columna; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return rslt;
}

// Driver code
int main()
{
    ifstream file("matriz3.txt");
    ofstream file2("multimatriz.txt");
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
        vector<vector<int>> resultado= mulMat(arreglo, arreglo2, filas,columnas, columnas2);
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
