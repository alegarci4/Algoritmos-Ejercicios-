#include <iostream>
#include <vector>
using namespace std;
int main() {
    int filas, columnas;
    cout << "Ingrese el n�mero de filas: ";
    cin >> filas;
    cout << "Ingrese el n�mero de columnas: ";
    cin >> columnas;
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout << "Ingrese el valor para la posici�n [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    int puntuacionTotal = 0;
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            if(matriz[i][j] % 2 == 0) {
                if(matriz[i][j] == 5) {
                    puntuacionTotal += 5;
                } else {
                    puntuacionTotal += 1;
                }
            } else {
                if(matriz[i][j] == 5) {
                    puntuacionTotal += 5;
                } else {
                    puntuacionTotal += 3;
                }
            }
        }
    }
cout << "Puntuaci�n total: " << puntuacionTotal << endl;
return 0;
}
