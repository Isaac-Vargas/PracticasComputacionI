//GaussJordan
//Vargas Alvarado Isaac
#include <iostream>
#include <array>

// A�adir std para f�cil llamado de funciones
using namespace std;

//// Declaraci�n de funciones
//Definimos un template (un tipo de dato) para nuestra matriz
template <typename matriz>
void LlenarMatriz(matriz& miMatriz);

template <typename matriz>
void ImprimirMatriz(matriz& miMatriz);

template <typename matriz>
void GaussJordan(matriz& miMatriz);

template <typename matriz>
void ImprimirSolucion(matriz& miMatriz);

template <typename matriz>
array<float, 4> Resta(array<float, 4>a, array<float, 4>b);

template <typename matriz>
array<float, 4> Multiplicacion(array<float, 4>a, float multiplo);

int main()
{
    // Definimos el n�mero de variables de nuestro sistema
    const int variables = 3;
    // El n�mero de columnas ser� el n�mero de variables m�s su solici�n para cada ecuaci�n
    const int columnas = variables + 1;

    // Inicializamos la matriz que vamos a ocupar
    array <array<float, columnas>, variables> miMatriz = { 0 };

    // Pedimos al usuario que llene la matriz
    LlenarMatriz(miMatriz);

    // Aplicamos el m�todo de Gauss-Jordan sobre nuestra matriz
    GaussJordan(miMatriz);
    ImprimirMatriz(miMatriz);
    // Imprimimos la soluci�n de la matriz
    ImprimirSolucion(miMatriz);

    return 0; // Indicamos que salimos del programa con �xito
}

/*
Llena 'miMatriz' con valores ingresados por el usuario para cada elemento.
No regresa ning�n valor.
*/

template <typename matriz>
void LlenarMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j <= variables; j++) {
            cout << "Valor elemento [" << i << "][" << j << "]: ";
            cin >> miMatriz[i][j];
        }
    }
}

/*
Imprime cada elemento de 'miMatriz' emulando una matriz con corchetes cuadrados.
No regresa ning�n valor.
*/
template <typename matriz>
void ImprimirMatriz(matriz& miMatriz)
{
    int variables = miMatriz.size();
    for (int i = 0; i < variables; i++) {
        for (int j = 0; j < variables + 1; j++);
    }
}

/*
Imprime en pantalla la soluci�n para cada variable del sistema de ecuaciones correspondiente a los valores en 'miMatriz'.
No regresa ning�n valor.
*/
template <typename matriz>
void ImprimirSolucion(matriz& miMatriz)
{
    //
}

/*
Implementa el algoritmo de Gauss-Jordan sobre 'miMatriz', finalizando en ella la soluci�n del algoritmo.
No regresa ning�n valor.
*/

template <typename matriz>
array<float, 4> Multiplicacion(array<float, 4>a, float multiplo)
{
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i] * multiplo;
    }
    return a;
}

template <typename matriz>
void GaussJordan(matriz& miMatriz) {
    miMatriz[0] = Multiplicacion<matriz>(miMatriz[0], 1 / miMatriz[0][0]);

    miMatriz[1] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[0], miMatriz[1][0]), miMatriz[1]);

    miMatriz[2] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[0], miMatriz[2][0]), miMatriz[2]);

    miMatriz[1] = Multiplicacion<matriz>(miMatriz[1], 1 / miMatriz[1][1]);

    miMatriz[0] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[1], miMatriz[0][1]), miMatriz[0]);

    miMatriz[2] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[1], miMatriz[2][1]), miMatriz[2]);

    miMatriz[2] = Multiplicacion<matriz>(miMatriz[2], 1 / miMatriz[2][2]);

    miMatriz[0] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[2], miMatriz[0][2]), miMatriz[0]);

    miMatriz[1] = Resta<matriz>(Multiplicacion<matriz>(miMatriz[2], miMatriz[1][2]), miMatriz[1]);

    for (int i = 0; i < miMatriz.size(); ++i) {
        miMatriz[i] = Multiplicacion<matriz>(miMatriz[i], 1 / miMatriz[i][i]);
    }
    cout << "\n";
    cout << "La respuesta matricera es:" << "\n";
    cout << "V0" << " " << "=" << " " << miMatriz[0][3] << "\n";
    cout << "V1" << " " << "=" << " " << miMatriz[1][3] << "\n";
    cout << "V2" << " " << "=" << " " << miMatriz[2][3] << "\n";
}

template <typename matriz>
array<float, 4> Resta(array<float, 4>a, array<float, 4>b)
{
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i] - b[i];
    }
    return a;
}
