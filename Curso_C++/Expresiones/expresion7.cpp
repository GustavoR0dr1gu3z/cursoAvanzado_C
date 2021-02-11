#include <iostream>

using namespace std;

int main(){

    float practica, teorico, participacion, promedio = 0;

    cout<<"Digite la nota de practica: "; cin>>practica;
    cout<<"Digite la nota teorica: "; cin>>teorico;
    cout<<"Digite la nota de participación: "; cin>>participacion;

    practica *= 0.30;
    teorico *= 0.60;
    participacion *= 0.10;

    promedio = practica+teorico+participacion;

    cout<<"\nSu promedio es: "<<promedio<<endl<<endl;


    return 0;
}