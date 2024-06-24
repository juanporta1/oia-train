#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ordenar(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int encontrarMayor(vector<int> lista)
{
    int mayor = 0;
    for (int i = 0; i < lista.size(); i++)
    {
        if (mayor == 0  || lista[i] > mayor)
        {
            mayor = lista[i];
        }
    }
    return mayor;
}

void imprimirConexiones(vector<vector<int>> lista)
{
    cout << "Inicio" << endl;

    for (int i = 0; i < lista.size(); i++)
    {
        cout << "Nodo1: " << lista[i][0] << ". Nodo2: " << lista[i][1] << ". Flecha: "<< lista[i][2] << endl; 
    }

    cout << "Final" << endl;
}

int serieparalelo(vector<int> t, vector<int> e)
{
    //Primer y Segundo valor son los nodos, tercer valor es el nombre de la flecha.
    //Cuarto y Quinto valor equivalen a el indice de ordenamiento que tiene el primer y seguno nodo respectivamente.
    vector<vector<int>> conexiones = {{1,2,1,0,10}};
    vector<int> nodos = {1,2};
    vector<int> flechas = {1};

    for (int accion = 0; accion < t.size(); accion++)
    {
        if (t[accion] == 1)
        {
            int nodoMenor = conexiones[e[accion] - 1][0];
            int nodoMayor = conexiones[e[accion] - 1][1];
            int flechaActual = conexiones[e[accion] - 1][2];
            

            conexiones.erase(conexiones.begin() + e[accion] - 1);
            int nuevoNodo = encontrarMayor(nodos) + 1;
            int nuevaFlecha = encontrarMayor(flechas) + 1;
            vector<int> nuevaConexion1 = {nodoMenor,nuevoNodo,nuevaFlecha};
            vector<int> nuevaConexion2 = {nuevoNodo,nodoMayor,flechaActual};
            conexiones.push_back(nuevaConexion1);
            conexiones.push_back(nuevaConexion2);
            sort(conexiones.begin(),conexiones.end(),ordenar);

            flechas.push_back(nuevaFlecha);
            sort(flechas.begin(), flechas.end());
            nodos.push_back(nuevoNodo);
            sort(nodos.begin(),nodos.end());
        }
        else if (t[accion] == 2)
        {
            int nodoMenor = conexiones[e[accion] - 1][0];
            int nodoMayor = conexiones[e[accion] - 1][1];
        
            int nuevoNodo = encontrarMayor(nodos) + 1;
            int nuevaFlechaMenor = encontrarMayor(flechas) + 1;
            int nuevaFlechaMayor = encontrarMayor(flechas) + 2;

            vector<int> nuevaConexion1 = {nodoMenor,nuevoNodo,nuevaFlechaMenor};
            vector<int> nuevaConexion2 = {nuevoNodo,nodoMayor,nuevaFlechaMayor};

            conexiones.push_back(nuevaConexion1);
            conexiones.push_back(nuevaConexion2);
            sort(conexiones.begin(),conexiones.end(),ordenar);

            flechas.push_back(nuevaFlechaMenor);
            flechas.push_back(nuevaFlechaMayor);
            sort(flechas.begin(), flechas.end());
            nodos.push_back(nuevoNodo);
            sort(nodos.begin(),nodos.end());

        }
    }

    
    imprimirConexiones(conexiones);

    return 0;
}


int main()
{

    int serie = serieparalelo(vector<int> {1,1,2,2,1,2,2}, vector<int> {1,1,2,3,2,2,2});
    return 0;
}