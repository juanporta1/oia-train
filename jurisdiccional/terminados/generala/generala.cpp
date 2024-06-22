#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int contar(vector<int> numeros, int x)
{
    int contador = 0;
    for (int i = 0; i < numeros.size(); i++)
    {
        if (numeros[i] == x){
            contador++;
        }
    }
    return contador;
}



void generala(int a,int b,int c,int d,int e)
{   
    vector<int> numeros = {a,b,c,d,e};
    vector<int> puntos = {0,0,0,0,0,0};
    vector<int> puntosDePartida(6);

    //Puntos individuales
    for (int i = 0; i < numeros.size(); i++)
    {
        puntos[numeros[i] - 1] += numeros[i];
        puntosDePartida[numeros[i] - 1] += numeros[i];
    }

    //Escalera
    vector<int> numerosCopia = numeros;
    sort(numerosCopia.begin(),numerosCopia.end());
    vector<int> cantidades(6);
    for (int i = 1; i <= 6;i++)
    {
        int cantidad = contar(numerosCopia,i);
        cantidades[i-1] = cantidad;
    }



    vector<vector<int>> casos = {{1,1,1,1,1,0},{1,0,1,1,1,1},{0,1,1,1,1,1}};
    int escalera = 0;

    for (int i = 0; i < 3; i++)
    {
        if (casos[i] == cantidades)
        {
            escalera = 20;
            break;
        }
    }
    puntosDePartida.push_back(escalera);

    //Full,Poker,Generala
    bool dosVeces = false;
    bool tresVeces = false;
    bool cuatroVeces = false;
    bool cincoVeces = false;
    for (int i = 1; i <= 6; i++)
    {   
        int cantidad = puntos[i - 1] / i;
        if (cantidad == 2)
        {
            dosVeces = true;
        }
        if (cantidad == 3)
        {
            tresVeces = true;
        }
        if (cantidad >= 4)
        {
            cuatroVeces = true;
        }
        if (cantidad == 5)
        {
            cincoVeces = true;
        }
        
    }

    if (dosVeces && tresVeces) puntosDePartida.push_back(30); else puntosDePartida.push_back(0);

    if (cuatroVeces || cincoVeces) puntosDePartida.push_back(40); else puntosDePartida.push_back(0);

    if (cincoVeces) puntosDePartida.push_back(50); else puntosDePartida.push_back(0);

    for (int i = 0; i < puntosDePartida.size();i++)
    {
        if (i < puntosDePartida.size() - 1)
        {
        cout << puntosDePartida[i] << ", ";
        }
        else cout << puntosDePartida[i] << ".";
    }
    
}

int main()
{
    generala(3,3,3,3,3);
    cout << endl;
    generala(1,3,4,6,5);
    cout << endl;
    generala(3,2,2,3,2);
}
