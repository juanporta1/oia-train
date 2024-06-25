#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dominando(string n,int d,vector<int> t, vector<int> a, vector<int> b)
{   
    
    vector<string> resultados;
    for (int i = 0; i < t.size();i++)
    {   
        int posA = a[i]-1;
        
        if (t[i] == 0)
        {
            int posB = b[i]-1;
            string nuevoNumero = "";
            for (int j = posA; j <= posB; j++)
            {
                nuevoNumero += n[j];
            }
            long long nuevoNumeroEntero = stoll(nuevoNumero);
            long division = nuevoNumeroEntero % d;
            resultados.push_back(to_string(division));
            
             
        }
        else
        {   
            int posB = b[i];
            string b = to_string(posB);
            n.erase(n.begin() + posA);
            n.insert(posA,b);
            
        }
    }
    return resultados;
}

int main()
{
    string n = "123456789101112";
    int d = 1000000007;
    vector<int> t = {1,0,0,1,0,0,1,0,1,1};
    vector<int> a = {1,1,6,9,1,2,4,7,7,6};
    vector<int> b = {7,15,15,8,9,5,4,7,6,7};
    vector<string> resultados = dominando(n,d,t,a,b);

    for (int i = 0; i < resultados.size(); i++)
    {
        cout << resultados[i] << endl;
    }
    return 0;
}