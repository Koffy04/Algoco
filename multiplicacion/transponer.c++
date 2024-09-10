#include <bits/stdc++.h> // Incluir todas las bibliotecas estándar
using namespace std;

// Función para multiplicar la matriz A por la transpuesta de B
vector<vector<int>> transpuesta(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int m = A.size();       // Número de filas de A
    int n = A[0].size();    // Número de columnas de A (y filas de B)
    int p = B.size();       // Número de filas de B (equivalente al número de columnas de B transpuesta)

    // Crear la matriz resultante de tamaño m x p, inicializada con ceros
    vector<vector<int>> C(m, vector<int>(p, 0));

    // Realizar la multiplicación de A con la transpuesta de B
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                // Aquí se multiplica A[i][k] por B[j][k], que es equivalente a B^T[k][j]
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    return C; // Devolver la matriz resultante
}

int main() {
    // Abrir el archivo de entrada "matriz3.txt"
    ifstream file("matriz3.txt");
    // Abrir el archivo de salida "transpuesta.txt"
    ofstream file2("transpuesta.txt");

    // Verificar si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1; // Terminar el programa si ocurre un error
    }
    
    int filas, columnas, filas2, columnas2;

    // Leer el número de filas y columnas de la primera matriz
    file >> filas >> columnas;
    // Inicializar la primera matriz con las dimensiones adecuadas
    vector<vector<int>> arreglo(filas, vector<int>(columnas));
    // Leer los elementos de la primera matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            file >> arreglo[i][j];
        }
    }

    // Leer el número de filas y columnas de la segunda matriz
    file >> filas2 >> columnas2;
    
    // Inicializar la segunda matriz con las dimensiones adecuadas
    vector<vector<int>> arreglo2(filas2, vector<int>(columnas2));
    // Leer los elementos de la segunda matriz
    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            file >> arreglo2[i][j];
        }
    }

    // Verificar si las matrices son multiplicables
    if (columnas != filas2) {
        cerr << "Las matrices no son multiplicables: el número de columnas de la primera matriz no coincide con el número de filas de la segunda matriz." << endl;
        return 1; // Terminar el programa si no son multiplicables
    } else {
        // Medir el tiempo de ejecución de la multiplicación
        auto inicio = chrono::high_resolution_clock::now();
        // Llamar a la función de multiplicación de matrices
        vector<vector<int>> resultado = transpuesta(arreglo, arreglo2);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        // Imprimir el tiempo de ejecución en microsegundos
        cout << "El tiempo es " << duracion.count() << " microsegundos" << endl;

        // Guardar el resultado en el archivo de salida
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas2; j++) {
                file2 << resultado[i][j] << " ";
            }
            file2 << "\n";
        }

        // Cerrar los archivos
        file.close();
        file2.close();
    }

    return 0; // Finalizar el programa correctamente
}
