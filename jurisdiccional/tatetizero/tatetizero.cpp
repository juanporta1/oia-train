#include <iostream>
#include <vector>
using namespace std;

bool verificarContrincante(vector<vector<int>> copia,int contrincante)
{
    for (int f = 0; f < 3; f++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (copia[f][c] != 0) continue;
            vector<vector<int>> copia2 = copia;
            copia2[f][c] = contrincante;
            
            for (int i = 0; i < 3; i++)
            {
                if (copia[0][i] == contrincante && copia[1][i] == contrincante && copia[2][i] == contrincante)
                {
                    return true;
                }
                else if (copia[i][0] == contrincante && copia[i][1] == contrincante && copia[i][2] == contrincante)
                {
                    return true;
                }
            }
            if ((copia[0][0] == contrincante && copia[1][1] && copia[2][2] == contrincante) || (copia[0][2] == contrincante && copia[1][1] == contrincante && copia[2][0] == contrincante))
            {
                return true;
            }
        }

    }
    return false;
}

vector<int> proximoJugador(vector<vector<int>> tablero)
{
    int j1 = 0;
    int j2 = 0;
    vector<int> retorno(2);
    for (int f = 0; f < 3; f++)
    {
        for(int c = 0; c < 3; c++)
        {
            if (tablero[f][c] == 1)j1++; else if (tablero[f][c] == 2) j2++;

            if (j1 == j2) retorno = {1,2};
            else retorno = {2,1};

        }
    }
    return retorno;
}
//0:vacio, 1:jugador 1, 2:jugador 2, 3: ganar, 4:perder, 5: empatar.
vector<vector<int>> tateti(vector<vector<int>> tablero)
{
    vector<int> info = proximoJugador(tablero);
    int juega = info[0];
    int contrincante = info[1];
    vector<vector<int>> muestra = tablero;
    for (int f = 0; f < 3; f++)
    {
        for(int c = 0; c < 3; c++)
        {   
            if (tablero[f][c]) continue;
            vector<vector<int>> copia = tablero;
            copia[f][c] = juega;
            for ( int i = 0; i < 3;i++)
            {
                if (copia[0][i] == juega && copia[1][i] == juega && copia[2][i] == juega)
                {
                    muestra[f][c] = 3;
                }
                else if (copia[i][0] == juega && copia[i][1] == juega && copia[i][2] == juega)
                {
                    muestra[f][c] = 3;
                }
                
                else
                {
                    if (verificarContrincante(copia,contrincante))
                    {
                        muestra[f][c] = 4;
                    }
                    else
                    {
                        muestra[f][c] = 5;
                    }
                }

            }
            if ((copia[0][0] == juega && copia[1][1] && copia[2][2] == juega) || (copia[0][2] == juega && copia[1][1] == juega && copia[2][0] == juega))
            {
                muestra[f][c] = 3;
            }
        }
    }
    return muestra;
}

int main()
{
    vector<vector<int>> tablero = {{1,2,0},
                            {1,0,2},
                            {0,0,0}};
    vector<vector<int>> muestra = tateti(tablero);

    for (int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {
            cout << muestra[i][j];
        }
        cout << endl;
    }
    return 0;
}