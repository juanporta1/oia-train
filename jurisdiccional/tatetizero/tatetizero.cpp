#include <iostream>
#include <vector>
using namespace std;

void imprimirTablero(vector<vector<int>> tablero)
{
    for (int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {
            switch (tablero[i][j])
            {
            case 0:
                cout << " . ";
                break;
            
            case 1:
                cout << " O ";
                break;
            
            case 2:
                cout << " X ";
                break;
            
            case 3:
                cout << " G ";
                break;
            
            case 4:
                cout << " P ";
                break;

            case 5:
                 cout << " E ";
                 break;
            
            default:
                break;
            }
        }
        cout << endl;
    }
}

bool verificarContrincante(vector<vector<int>> copia,int contrincante)
{
    for (int f = 0; f < 3; f++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (copia[f][c] != 0) continue;
            vector<vector<int>> copia2 = copia;
            copia2[f][c] = contrincante;
            
            if (copia2[0][c] == contrincante && copia2[1][c] == contrincante && copia2[2][c] == contrincante)
            {
                
                return true;
            }
            else if (copia2[f][0] == contrincante && copia2[f][1] == contrincante && copia2[f][2] == contrincante)
            {
                
                return true;
            }
            
            else if (copia2[0][0] == contrincante && copia2[1][1] == contrincante && copia2[2][2] == contrincante)
            {
                imprimirTablero(copia2);
                return true;
            }
            else if (copia2[0][2] == contrincante && copia2[1][1] == contrincante && copia2[2][0] == contrincante){
                imprimirTablero(copia2);
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
void tateti(vector<vector<int>> tablero)
{
    vector<int> info = proximoJugador(tablero);
    int juega = info[0];
    int contrincante = info[1];
    cout << juega << endl;
    cout << contrincante << endl;
    vector<vector<int>> muestra = tablero;
    for (int f = 0; f < 3; f++)
    {
        for(int c = 0; c < 3; c++)
        {   
            if (tablero[f][c] != 0) continue;
            vector<vector<int>> copia = tablero;
            copia[f][c] = juega;
            
            if (copia[0][c] == juega && copia[1][c] == juega && copia[2][c] == juega)
            {
                muestra[f][c] = 3;
                 
            }
            else if (copia[f][0] == juega && copia[f][1] == juega && copia[f][2] == juega)
            {
                muestra[f][c] = 3;
                
            }
            
            else if ((copia[0][0] == juega && copia[1][1] == juega && copia[2][2] == juega) || (copia[0][2] == juega && copia[1][1] == juega && copia[2][0] == juega))
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
    }
    imprimirTablero(muestra);
}

int main()
{
    // vector<vector<int>> tablero(3); 
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         string entrada;
    //         cout << "Ingrese la posicion Fila " << i + 1 << ", Columna " << j + 1 << ":"; cin >> entrada;
            
    //         if (entrada == ".") tablero[i][j] = 0;
    //         else if (entrada == "O") tablero[i][j] = 1;
    //         else if (entrada == "X") tablero[i][j] = 2;
            

    //     }
    // }
    vector<vector<int>> tablero = { {0,0,0},
                                    {1,2,2},
                                    {2,1,1} }; 
    tateti(tablero);

    
    return 0;
}