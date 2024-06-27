#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> palogol(vector<vector<int>> pelotazos)
{
    vector<string> resultados;
    for (vector<int> pelotazo : pelotazos)
    {
        if (pelotazo[0] > 0 && pelotazo[0] < 732 && pelotazo[1] < 232)
        {
            resultados.push_back("GOL");
        }
        else if((pelotazo[0] > 0 && pelotazo[0] < 732 && pelotazo[1] == 232) || (pelotazo[0] == 0 || pelotazo[0] == 732 && pelotazo[1] < 232))
        {
            resultados.push_back("PALO");
        }
        else
        {
            resultados.push_back("FUERA");
        }
    }
    return resultados;
}

int main()
{

    vector<vector<int>> pelotazos = {{2,3},{0,100},{1000,1000},};
    vector<string> resultados = palogol(pelotazos);

    for (string resultado : resultados)
    {
        cout << resultado << endl;
    }
    return 0;
}