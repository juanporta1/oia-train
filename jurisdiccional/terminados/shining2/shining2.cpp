#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void imprimirTridimensional(vector<vector<vector<int>>> caminos)
{
    cout << "INCIO TRIDIMENSIONAL" << endl;
    for(int i = 0; i < caminos.size(); i++)
    {
        cout << "inicio bidimensional" <<endl;
        for ( int j = 0; j < caminos[i].size(); j++)
        {
            cout << caminos[i][j][0] << "," << caminos[i][j][1] << endl;
        }
        cout << "final bidimensional" << endl;
    }
    cout << "FINAL TRIDIMENSIONAL" << endl;    
}

bool yaExiste(vector<vector<int>> posiciones, vector<int> posC)
{
    
    for (int i = 0;i < posiciones.size(); i++)
    {
        if(posiciones[i] == posC)
        {
            return true;
        }
    }
    return false;
}

int shining(vector<int> fila, vector<int> columna,vector<int> vidaMaxima, vector<int> vidaActual, int d,vector<vector<string>> mapa)
{   
    
    vector<vector<int>> posicionesFinales;
    int cantMovAct = 0;
    vector<vector<int>> posibilidadesDeUbicacion;

    vector<vector<int>> ubicaciones(fila.size() - 1);
    vector<vector<int>> vida(fila.size() - 1);
    vector<vector<int>> curandero(2);
    
    for (int i= 0; i < fila.size(); i++)
    {
        
        if (i == 0)
        {
            
            
            curandero[0] = {fila[0],columna[0]};
            curandero[1] = {vidaMaxima[0], vidaActual[0]};
            
            
        }
        else
        {
            ubicaciones[i-1] = {fila[i],columna[i]};
            vida[i-1] = {vidaMaxima[i],vidaActual[i]};
            
        }
        
    }

    posibilidadesDeUbicacion.push_back(curandero[0]);
    
    vector<vector<vector<int>>> caminos = {{{curandero[0][0],curandero[0][1]}}};
    vector<vector<vector<int>>> caminosProximos;
    
    while(cantMovAct <= d)
    {      
        vector<vector<vector<int>>> caminosProximos(0);
        int cantidad = caminos.size();
        
        for(int camino = 0; camino < cantidad;camino++)
        {
             
            int f = caminos[camino].back()[0];
            int c = caminos[camino].back()[1];
            
            if (c+1 < mapa[0].size() && mapa[f][c+1] != "X" && cantMovAct < d)
            {
                vector<vector<int>> nuevoCamino = caminos[camino];
                nuevoCamino.push_back(vector<int> {f,c+1});
                caminosProximos.push_back(nuevoCamino);
            }
            if (c-1 >= 0 && mapa[f][c-1] != "X")
            {
                vector<vector<int>> nuevoCamino = caminos[camino];
                nuevoCamino.push_back(vector<int> {f,c-1});
                caminosProximos.push_back(nuevoCamino);
            }
            if (f+1 < mapa.size() && mapa[f+1][c] != "X")
            {
                vector<vector<int>> nuevoCamino = caminos[camino];
                nuevoCamino.push_back(vector<int> {f+1,c});
                caminosProximos.push_back(nuevoCamino);
            }
            
            if (f-1 >= 0 && mapa[f-1][c] != "X")
            {
                vector<vector<int>> nuevoCamino = caminos[camino];
                nuevoCamino.push_back(vector<int> {f-1,c});
                caminosProximos.push_back(nuevoCamino);
            }
            
        }
        cantMovAct++;
        
        for (int i = 0; i < caminos.size();i++)
        {
            if(!yaExiste(posibilidadesDeUbicacion,caminos[i].back()) && !yaExiste(ubicaciones,caminos[i].back()))
            {
                posibilidadesDeUbicacion.push_back(caminos[i].back());
            }
        }
        caminos = caminosProximos;
        

        
    }
    
    int maximaCuracion = 0;
    vector<int> posGanadora;

    for (int pos = 0; pos < posibilidadesDeUbicacion.size(); pos++)
    {
        int totalCuracion; 
        int curF = posibilidadesDeUbicacion[pos][0];
        int curC = posibilidadesDeUbicacion[pos][1];

        if (curandero[1][0] - curandero[1][1] > 10) totalCuracion = 10;
        else totalCuracion = curandero[1][0] - curandero[1][1];
        
        if (maximaCuracion == 0 || totalCuracion > maximaCuracion)
        {
            maximaCuracion = totalCuracion;
            posGanadora = posibilidadesDeUbicacion[pos];
        }
        for (int personaje = 0; personaje < ubicaciones.size(); personaje++)
        {
            int perF = ubicaciones[personaje][0];
            int perC = ubicaciones[personaje][1];
            
            if ((abs(perF - curF) + abs(perC - curC)) <= 2)
            {
                if (vida[personaje][0] - vida[personaje][1] >= 10) totalCuracion = 10;
                
                else totalCuracion = vida[personaje][0] - vida[personaje][1];
                if (maximaCuracion == 0 || totalCuracion >= maximaCuracion)
                {
                    maximaCuracion = totalCuracion;
                    posGanadora = posibilidadesDeUbicacion[pos];
                }
            }
        }
        

    }
    cout << "La maxima curacion posible es " << maximaCuracion << endl;
    cout << posGanadora[0] << "," << posGanadora[1] << endl;
    
    return 0;
}

int main()
{

    vector<vector<string>> mapa1 = {{".",".","X","X",".","."},
                                    {".",".",".","X","X","X"},
                                    {".",".",".","X",".","."},
                                    {".",".",".",".",".","."}};
    vector<int> filas1 = {2,3,0,2,0,3};
    vector<int> columnas1 = {2,3,5,0,4,1};
    vector<int> vidaMaxima1 = {13,40,40,50,40,6};
    vector<int> vidaActual1 = {10,34,1,48,32,1};
    int d1 = 5;

    int result1 = shining(filas1,columnas1,vidaMaxima1,vidaActual1,d1,mapa1);

    vector<vector<string>> mapa2 = {{".","."},
                                    {".","."},};
    vector<int> filas2 = {0,1};
    vector<int> columnas2 = {0,1};
    vector<int> vidaMaxima2 = {13,40};
    vector<int> vidaActual2 = {13,40};
    int d2 = 3;
    int result2 = shining(filas2,columnas2,vidaMaxima2,vidaActual2,d2,mapa2);
    return 0;
}