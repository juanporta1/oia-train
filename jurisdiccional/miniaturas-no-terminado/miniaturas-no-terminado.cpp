#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
void imprimirMatriz(vector<vector<vector<int>>> matriz){
    int filas = matriz[0].size();
    int columnas = matriz[0][0].size();
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0;j < columnas; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << matriz[i][j][k] << ",";
            }
            cout << "   ";
        }
        cout << endl;
    }
}

vector<vector<vector<int>>> iniciaizar(vector<vector<int>> rojo,vector<vector<int>> verde,vector<vector<int>> azul)
{   
    int filas = rojo.size();
    int columnas = rojo[0].size();

    vector<vector<vector<int>>> colores = {rojo, verde, azul};

    vector<vector<vector<int>>> matriz(filas, vector<vector<int>>(columnas, vector<int>(3)));

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0;j < columnas; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                matriz[i][j][k] = colores[k][i][j];
            }
        }
    }
    return matriz;
}

vector<vector<int>> promediarColores(vector<vector<int>> color, int k, int l)
{   
    
    int n = color.size();
    int m = color[0].size();
    
    vector<vector<int>> colorNuevo(k , vector<int>(l));
    
    int posicion[2] = {0,0};

    while (true)
    {
        if ((n/k) - 1 == posicion[0] && (m/l) - 1 == posicion[1])
    }
}

vector<vector<vector<int>>> miniatura(int k, int l,vector<vector<int>> rojo,vector<vector<int>> verde,vector<vector<int>> azul)
{
    

}



int main()
{
    vector<vector<int>> rojo = {{10,10,10},
                                {10,100,10},
                                {10,10,10}};
    vector<vector<int>> verde = {{1,1,1},
                                {1,1,1},
                                {1,1,1}};
    vector<vector<int>> azul = {{100,100,1},
                                {100,100,2},
                                {6,5,3}};
    vector<vector<vector<int>>> matriz = iniciaizar(rojo, verde, azul);
    imprimirMatriz(matriz);
    return 0;
}