#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> vector1 = {1,1,1};
    vector<int> vector2 = {1,0,1};
    bool resultado = vector1 == vector2;
    cout << resultado;
}
