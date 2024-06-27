#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> pizarra;

void agregar(int x)
{
    return pizarra.push_back(x);
}

void contar(int a, int b)
{
    int contador = 0;
    for (int i = a; i <= b; i++)
    {
        for (int numero : pizarra)
        {
            if (numero == i)
            {
                contador += 1;
            }
        }
    }
    cout << contador << endl;
}

int main()
{
    vector<int> acciones = {0,1,1,0,1,1,1,0,0,0};
    vector<vector<int>> numeros = {{1,1000000},{10},{20},{5,20},{40},{50},{19},{5,20},{40,50},{1,1000}};

    for (int i = 0; i < acciones.size(); i++)
    {
        if (acciones[i] == 0)
        {
            contar(numeros[i][0],numeros[i][1]);
        }
        else
        {
            agregar(numeros[i][0]);
        }
    }
    return 0;
}