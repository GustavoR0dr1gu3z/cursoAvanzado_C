#include <iostream>

using namespace std;

int main(){

    int n1, n2, suma=0, resta=0, multiplicacion=0;
    float division=0.0;

    cout<<"Digite un numero: "; cin>>n1;

    cout<<"Digite otro numero: "; cin>>n2;

    suma = n1 + n2;    
    resta = n1 - n2;
    multiplicacion = n1 * n2;
    division = n1 / n2;


    cout<<"La suma ente los numeros "<<n1<<" y "<<n2<<" es: "<<suma<<endl;
    cout<<"La resta ente los numeros "<<n1<<" y "<<n2<<" es: "<<resta<<endl;
    cout<<"La multiplicacion ente los numeros "<<n1<<" y "<<n2<<" es: "<<multiplicacion<<endl;
    cout<<"La division ente los numeros "<<n1<<" y "<<n2<<" es: "<<division<<endl;


    return 0;
}