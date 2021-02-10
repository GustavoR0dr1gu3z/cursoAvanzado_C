#include <iostream>

using namespace std;

int main(){

    float x,y,aux;

    cout<<"Digite el valor de X: "; cin>>x;
    cout<<"Digite el valor de Y: "; cin>>y;

    cout<<"Usted digitó el valor de X: "<<x<<endl;
    cout<<"Usted digitó el valor de Y: "<<y<<endl;

    aux = x;
    x = y;
    y = aux;

    cout<<"\n\nUsted digitó el valor de X: "<<x<<endl;
    cout<<"Usted digitó el valor de Y: "<<y<<endl;


    return 0;
}