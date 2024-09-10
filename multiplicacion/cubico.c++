#include <bits/stdc++.h> // Incluye muchas bibliotecas estándar (no recomendado en producción)
using namespace std;

// Función para multiplicar dos matrices
vector<vector<int>> mulMat(vector<vector<int>> mat1, vector<vector<int>> mat2, int fila, int columna, int columna2) {
    // Inicializar una matriz resultado con ceros, de tamaño filas x columnas2
    vector<vector<int>> rslt(fila, vector<int>(columna2, 0));

    cout << "Multiplication of given two matrices is:\n";

    // Bucle para realizar la multiplicación de matrices
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < columna2; j++) {
            rslt[i][j] = 0; // Inicializar cada celda del resultado
            for (int k = 0; k < columna; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j]; // Sumar el producto de los elementos correspondientes
            }
        }
    }
    return rslt; // Devolver la matriz resultado
}

// Función principal
int main() {
    // Abrir el archivo de entrada "matriz3.txt"
    ifstream file("matriz3.txt");
    // Abrir el archivo de salida "multimatriz.txt"
    ofstream file2("multimatriz.txt");

    // Verificar si el archivo de entrada se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1; // Terminar el programa con un código de error
    }
    
    int filas, columnas, filas2, columnas2;

    // Leer el número de filas y columnas de la primera matriz
    file >> filas >> columnas;
    // Inicializar la primera matriz con las dimensiones leídas
    vector<vector<int>> arreglo(filas, vector<int>(columnas));
    // Leer los elementos de la primera matriz
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            file >> arreglo[i][j];
        }
    }

    // Leer el número de filas y columnas de la segunda matriz
    file >> filas2 >> columnas2;
    // Inicializar la segunda matriz con las dimensiones leídas
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
        return 1; // Terminar el programa con un código de error
    } else {
        // Medir el tiempo de ejecución de la multiplicación de matrices
        auto inicio = chrono::high_resolution_clock::now();
        // Llamar a la función que multiplica las matrices
        vector<vector<int>> resultado = mulMat(arreglo, arreglo2, filas, columnas, columnas2);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;
        cout << "El tiempo es " << duracion.count() << " microsegundos" << endl; // Mostrar el tiempo de ejecución

        // Escribir el resultado de la multiplicación en el archivo de salida
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

    return 0; // Indicar que el programa finalizó correctamente
}
