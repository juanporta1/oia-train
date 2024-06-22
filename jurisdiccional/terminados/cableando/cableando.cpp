#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int verificar(int variable)
{
    while (true)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Vuelva a ingresar el valor: "; cin >> variable;
            }
            else return variable;
        }
}
bool comparar(int a, int b)
{
    return a > b;
}

int main()
{
    int pueblos;
    int central;
    
    cout << "Ingrese el kilometro de ruta donde se encuentra la Megacentral: "; cin >> central;
    central = verificar(central);
    cout << "Ingrese la cantidad de pueblos que se quieren conectar a la Megacentral: "; cin >> pueblos;
    pueblos = verificar(pueblos);

    vector<int> pueblosUbicacion(pueblos);
    for (int i = 0; i < pueblos; i++)
    {
        int kilometro; 
        cout << "Ingrese el kilometro en el que se encuentra el pueblo " << i+1<< ": "; cin >> kilometro;
        kilometro = verificar(kilometro);

        pueblosUbicacion[i] = kilometro;

    }

    // cout << "Kilometro en el que se encuentra la Megacentral: " << central << endl;
    // cout << "Cantidad de pueblos: " << pueblos  << endl;
    

    pueblosUbicacion.push_back(central);
    sort(pueblosUbicacion.begin(), pueblosUbicacion.end(),comparar);
    int totalCable = 0;
    for (int i = 0; i < pueblosUbicacion.size(); i++)
    {   
        
        if (pueblosUbicacion[i] == central)
        {
            cout << "Central" << ": " << pueblosUbicacion[i] << endl;
            continue;
        }
        cout << "Pueblo " << i + 1 << ": " << pueblosUbicacion[i] << endl;
    }
    for (int i = 0; i < pueblosUbicacion.size(); i++)
    {

        if (i < pueblosUbicacion.size() - 1)
        {
            totalCable += pueblosUbicacion[i] - pueblosUbicacion[i+1];
        }
    }

    cout << "El total de cable necesario es: " << totalCable;

    return 0;
}