#include <iostream>
#include <vector>

using namespace std;

vector<int> buscarTamaño(vector<vector<int>> posiciones)
{

    vector<int> maximos(2);
    for(vector<int> pos : posiciones)
    {
        maximos[0] = max(maximos[0],pos[0]);
        maximos[1] = max(maximos[1],pos[1]);
    }
    return maximos;
}

vector<int> radiotaxi(vector<int> taxiX, vector<int> taxiY, vector<int> clienteX,vector<int> clienteY)
{
    vector<vector<int>> informacion;
    vector<vector<int>> ubicacionTaxis;
    vector<vector<int>> ubicacionClientes;
    for(auto x : taxiX)
    {
        for (auto y : taxiY)
        {
            ubicacionTaxis.push_back(vector<int> {x,y});
        }
    }

    for(auto x : clienteX)
    {
        for (auto y : clienteY)
        {
            ubicacionClientes.push_back(vector<int> {x,y});
        }
    }

    vector<vector<int>> maximos= {buscarTamaño(ubicacionTaxis),buscarTamaño(ubicacionClientes)};
    
    
}


int main()
{


    return 0;
}