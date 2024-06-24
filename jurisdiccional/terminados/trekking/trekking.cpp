#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void imprimirBidimensional(vector<vector<int>> vector)
{
    cout << "Aqui empieza el vector bidimensional" << endl;
    for (int i = 0; i < vector.size(); i++)
        {
            cout << vector[i][0] << "," << vector[i][1] << endl;
        }
}
void imprimirTridimensional(vector<vector<vector<int>>> vector)
{
    cout << "Aqui empieza el vector TRIDIMENSIONAL" << endl;
    for (int i = 0; i < vector.size(); i++)
    {
        imprimirBidimensional(vector[i]);
    }
    cout << "Aqui termina el vector TRIDIMENSIONAL" << endl;
}



bool yaPaso(vector<vector<int>> camino, vector<int> pos)
{
    for (int i= 0; i<camino.size();i++)
    {
        if (camino[i] == pos)
        {
            return true;
        }
    }
    return false;
}



int trekking(vector<vector<int>> mapa)
{
    vector<vector<vector<int>>> caminos = {{{0,0}}};
    vector<vector<vector<int>>> caminosConSolucion(0);
    int filas = mapa.size() - 1;
    int columnas = mapa[0].size() - 1;
    vector<int> posFinal = {filas,columnas};
    
    while (caminos.size() != 0)    
    {
        vector<int> ultP = caminos[0][caminos[0].size() - 1];
        int f = ultP[0];
        int c = ultP[1];
        if (c+1 <= columnas && ((mapa[f][c + 1] - mapa[f][c])*-1 <= 150 && (mapa[f][c + 1] - mapa[f][c])*-1 >= 0) && !yaPaso(caminos[0],vector<int> {f,c+1}))
        {
            vector<vector<int>> nuevoCamino = caminos[0];
            nuevoCamino.push_back(vector<int> {f,c+1});
            // cout << "Entro" << endl;
            if (vector<int> {f,c+1} == posFinal)caminosConSolucion.push_back(nuevoCamino);
            else caminos.push_back(nuevoCamino);
        }
        if (c-1 >= 0 && ((mapa[f][c - 1] - mapa[f][c])*-1 <= 150 && (mapa[f][c - 1] - mapa[f][c])*-1 >= 0) && !yaPaso(caminos[0],vector<int> {f,c-1})) 
        {
            vector<vector<int>> nuevoCamino = caminos[0];
            nuevoCamino.push_back(vector<int> {f,c-1});
            
            if (vector<int> {f,c-1} == posFinal)caminosConSolucion.push_back(nuevoCamino);
            else caminos.push_back(nuevoCamino);
        }
        if (f + 1 <= filas && ((mapa[f + 1][c ] - mapa[f][c])*-1 <= 150 && (mapa[f + 1][c] - mapa[f][c])*-1 >= 0) && !yaPaso(caminos[0],vector<int> {f+1,c}))
        {
            vector<vector<int>> nuevoCamino = caminos[0];
            nuevoCamino.push_back(vector<int> {f+1,c});
            if (vector<int> {f+1,c} == posFinal)caminosConSolucion.push_back(nuevoCamino);
            else caminos.push_back(nuevoCamino);
        }
        if (f-1 >= 0 && ((mapa[f - 1][c ] - mapa[f][c])*-1 <= 150 && (mapa[f - 1][c] - mapa[f][c])*-1 >= 0) && !yaPaso(caminos[0],vector<int> {f-1,c}))
        {
            vector<vector<int>> nuevoCamino = caminos[0];
            nuevoCamino.push_back(vector<int> {f - 1,c});
            if (vector<int> {f-1,c} == posFinal)caminosConSolucion.push_back(nuevoCamino);
            else caminos.push_back(nuevoCamino);
                
            
        }

        caminos.erase(caminos.begin());
    }

    
    int mayorEsfuerzo  = 0;
    vector<vector<int>> caminoGanador(0);
    for ( int camino = 0; camino < caminosConSolucion.size(); camino++)
    {
        int totalEsfuerzo = 0;
        vector<vector<int>> camAct = caminosConSolucion[camino];
        for (int pos = 0; pos < camAct.size();pos++)
        {   
            if (pos == 0) continue;
            else if ( pos != 0 && pos != camAct.size())
            {
                int esfuerzo = (mapa[camAct[pos-1][0]][camAct[pos-1][1]] - mapa[camAct[pos][0]][camAct[pos][1]]);

                totalEsfuerzo += pow(esfuerzo,2);
            }
        }
        if (totalEsfuerzo < mayorEsfuerzo || mayorEsfuerzo == 0)
        {
            mayorEsfuerzo = totalEsfuerzo;
            caminoGanador = camAct;
        }
        
    }
    
    if ( caminoGanador.size() != 0){
        cout << "El camino con menos esfuerzo tiene: " << mayorEsfuerzo << endl;
        for (int i = 0;i < caminoGanador.size(); i++)
        {
        cout << caminoGanador[i][0] << "," << caminoGanador[i][1] << endl;
        }
    }
    else
    {
        cout << "No existe un camino posible" << endl;
        cout << -1;
    }
    

     
    
    return 0;
}

int main ()
{
    vector<vector<int>> mapa1 = {{10,20,30,40},
                                {50,60,70,80}};
    vector<vector<int>> mapa2 = {{10,160,300,40},
                                {50,160,450,80}};
    vector<vector<int>> mapa3 = {{10,350,500},
                                {50,200,650}};
    vector<vector<int>> mapa4 = {{200,-150,0},
                                {100,50,10}};

    int esfuerzo = trekking(mapa4);

    

    return 0;
}