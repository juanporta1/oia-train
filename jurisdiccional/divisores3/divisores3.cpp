#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool esPrimo(int n)
{
    
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


vector<int> divisores(int n, int m)
{
    
    vector<int> resultados(2);
    int numero = n;
    int agustinTotal = 0;
    while(numero != 1)
    {   
        
        int puntajeMasBajo = 0;
        int divisorMasBajo = 0;
        for (int i = 2; i <= floor(numero / 2); i++)
        {   
            
            if (!esPrimo(i)) continue;
            int potenciaDeNumero = pow(numero,2);
            int puntajeActual = pow(potenciaDeNumero%m,2);
            if (puntajeMasBajo == 0) {puntajeMasBajo = puntajeActual; divisorMasBajo = i;}
            else {puntajeMasBajo = min(puntajeActual,puntajeMasBajo); divisorMasBajo = i;}
            
        }
        cout<< puntajeMasBajo << endl;
        agustinTotal += puntajeMasBajo;
        numero /= divisorMasBajo;
        if (esPrimo(numero) || numero == 1) break;
    }
    resultados.push_back(agustinTotal);
    cout << resultados[0] << endl;
    return resultados;
}



int main()
{

    vector<int> resultados = divisores(100,10);
    return 0;
}