#include <iostream>
#include <string>
#include <vector>
using namespace std;

void imprimirUnidimensional(vector<int> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i] << endl;
    }
}

void imprimirBidimensional(vector<vector<int>> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i][0] << "," << lista[i][1] << endl;
    }
}

void imprimirTridimensional(vector<vector<vector<int>>> lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        imprimirBidimensional(lista[i]);
    }
}
bool noComparte(vector<vector<int>> posiciones, vector<int> posicion)
{

    vector<int> numerosA;
    for (vector<int> pos : posiciones)
    {
        for (int i = pos[0]; i <= pos[1]; i++)
        {
            numerosA.push_back(i);
        }
    }
    vector<int> numerosB;
    for (int i = posicion[0]; i <= posicion[1]; i++)
    {
        numerosB.push_back(i);
    }

    for (int numero : numerosB)
    {
        for (int comparacion : numerosA)
        {
            if (numero == comparacion)
            {
                return false;
            }
        }
    }
    return true;
}

int cubrecadena(string s, vector<string> t)
{
    vector<vector<int>> posiciones;
    for(string tipo : t)
    {
        
        int largo = tipo.length() - 1;
        for(int i = 0; i < s.length() - largo; i++)
        {
            if (s.substr(i, largo+1) == tipo)
            {
                posiciones.push_back(vector<int> {i, i + largo});
            }
            
        }
        
    }
    imprimirBidimensional(posiciones);
    vector<vector<vector<int>>> combinaciones;
    for (vector<int> posPrincipal : posiciones)
    {
        vector<vector<int>> combinacion = {posPrincipal};
        for ( vector<int> posComparacion : posiciones)
        {
            if (noComparte(combinacion,posComparacion) || combinacion.size() == 0)
            {
                combinacion.push_back(posComparacion);
            }
        }
        combinaciones.push_back(combinacion);
    }
    

    int minimo;
    for(vector<vector<int>> combinacion : combinaciones)
    {
        int posicionesOcupadas = 0;
        for(vector<int> pos : combinacion)
        {
            for( int i = pos[0]; i <= pos[1]; i++)
            {
                posicionesOcupadas += 1;
            }
        }
        
        if (minimo == 0 ||  s.length() - posicionesOcupadas < minimo)
        {
            minimo = s.length() - posicionesOcupadas;
        }
    }
    return minimo;
}

int main()
{

    vector<string> t = {"ABC","CDE","DEC"};
    string s = "ABCDECDE";

    int min = cubrecadena(s,t);
    cout << min << endl;
    return 0;
}