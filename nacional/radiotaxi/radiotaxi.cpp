#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

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

bool ordenarPorDistancias(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}


vector<int> radiotaxi(vector<int> taxiX, vector<int> taxiY, vector<int> clienteX,vector<int> clienteY)
{
    vector<vector<int>> informacion;
    vector<vector<int>> ubicacionTaxis;
    vector<vector<int>> ubicacionClientes;
    for(int i = 0; i < taxiX.size(); i++)
    {
    
        ubicacionTaxis.push_back(vector<int> {taxiX[i],taxiY[i]});
    
    }

    for(int i = 0; i < taxiX.size(); i++)
    {
    
        ubicacionClientes.push_back(vector<int> {clienteX[i],clienteY[i]});
    
    }

    vector<vector<vector<int>>> distancias;
    for (int j = 0; j < ubicacionClientes.size() - 1; j++)
    {
        vector<vector<int>> masCercanosCliente;
        for (int i = 0; i < ubicacionTaxis.size(); i++)
        {
            vector<int> distancia = {abs(ubicacionClientes[j][0] - ubicacionTaxis[i][0]) + abs(ubicacionClientes[j][1] - ubicacionTaxis[i][1]), i};
            masCercanosCliente.push_back(distancia);
        }
        distancias.push_back(masCercanosCliente);
    }
    

    for (vector<vector<int>>& distanciasCliente : distancias)
    {
        sort(distanciasCliente.begin(), distanciasCliente.end(),ordenarPorDistancias);
    }
    
    vector<vector<vector<int>>> posibilidades;

    
        
    for (int i = 0; i < distancias[0].size(); i++)
    {
       vector<vector<int>> posibilidad = {{distancias[0][i]}}; 
    }



    for (vector<vector<int>>& distanciasCliente : distancias)
    {
        cout << "Inicio cliente" << endl;
        for (vector<int> info : distanciasCliente)
        {
            cout << info[0] << ";" << info[1] << endl;
        }
        cout << "Final cliente" << endl;
    }


    

    return vector<int> {};
}


int main()
{
    vector<int> taxisX = {1,3,5};
    vector<int> taxisY = {1,5,1};
    vector<int> clientesX = {1,4};
    vector<int> clientesY = {5,3};
    vector<int> recogimiento = radiotaxi(taxisX,taxisY,clientesX,clientesY);

    return 0;
}