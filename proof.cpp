#include <iostream>
using namespace std;

class Persona
{
    public:
    int edad;
    string nombre;

    public:

    Persona(string _nombre, int _edad)
    {
        nombre = _nombre;
        edad = _edad;
    }

    void setEdad(int _edad)
    {
        edad = _edad;
    }
    int getEdad()
    {
        return edad;
    }
    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }
    string getNombre()
    {
        return nombre;
    }

};


int main(){
    
    Persona Persona1("Juan", 17);
    cout << Persona1.nombre << endl << Persona1.edad;
    return 0 ;

}
