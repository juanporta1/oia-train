#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<int> cadenas(vector<int> numeros)
{
    vector<int> valores(0);
    for (int i = 0; i < numeros.size(); i++)
    {
        int numero = numeros[i];
        int divisorActual = numero;
        int contador = 2;
        int total = numero;
        while (divisorActual != 1)
        {
            if (divisorActual % contador == 0)
            {
                divisorActual /= contador;
                contador = 2;
                total += divisorActual;
                
                
            }
            else
            {
                contador++;
            }
        }
        
        valores.push_back(total);
    }

    return valores;
}

int main()
{
    vector<int> numeros(0);
    while (true)
    {
        int numero;
        cout << "Ingrese un numero(Si ingresa 0 el programa le dara los resultados): "; cin >> numero;
        while (true)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingreselo nuevamente: "; cin >> numero;

            }
            else break;
        }
        if (numero == 0) break;
        else
        {
            numeros.push_back(numero);
        }

        
    }
    
    vector<int> valores = cadenas(numeros);

    for (int i = 0; i < valores.size();i++)
    {
        cout << valores[i] << endl;
    }

    


}