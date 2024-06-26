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
    for (vector<int> pos : posiciones)
    {
        if(pos[1] <= posicion[0])
        {
            return false;
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

    vector<vector<vector<int>>> combinaciones;
    for (vector<int> posPrincipal : posiciones)
    {
        vector<vector<int>> combinacion;
        for ( vector<int> posComparacion : posiciones)
        {
            if (noComparte(combinacion,posComparacion) || combinacion.size() == 0)
            {
                combinacion.push_back(posComparacion);
            }
        }
        combinaciones.push_back(combinacion);
    }
    imprimirTridimensional(combinaciones);

    int minimo;
    for(vector<vector<int>> combinacion : combinaciones)
    {
        vector<int> posicionesOcupadas;
        for(vector<int> pos : combinacion)
        {
            for( int i = pos[0]; i <= pos[1]; i++)
            {
                posicionesOcupadas.push_back(i);
            }
        }
        int cantidadOcupada = posicionesOcupadas.size();
        if (minimo == 0 ||  s.length() - cantidadOcupada < minimo)
        {
            minimo = s.length() - cantidadOcupada;
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