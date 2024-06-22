#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
int pedirNumero(string texto)
{
        int numero; 
        cout << texto ; cin >> numero;    
        while(true){
            if (cin.fail())
            {
                
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vuelve a ingresar el numero: "; cin >> numero;  
            }
            else break;  
        }
        return numero;
}

void dividiendo(int num, int  veces)
{
    float numero = num;
    for(int i = 0; i < veces; i++)
    {
        numero = numero / 2;
        numero = trunc(numero);
        cout << numero << endl;
    }
}

int main()
{
    int numero = 1;
    while (numero)
    {   
        numero = pedirNumero("Ingrese un numero: ");
        if (!numero) break;
        int veces = pedirNumero("Ingrese la cantidad de veces que quiere dividir: ");
        dividiendo(numero,veces);
    }
    
}





