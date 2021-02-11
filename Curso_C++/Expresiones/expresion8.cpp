#include <iostream>
#include <math.h>

using namespace std;

int main(){

    float ca, co, hip, aux;

    cout<<"Digite el Cateto Opuesto: "; cin>>co;
    cout<<"Digite el Cateto Adyacente: "; cin>>ca;

    aux = ((pow(co,2))+(pow(ca,2)));
    hip = sqrt(aux);

    cout<<"\nLa hipotenusa es: "<<hip<<endl<<endl;


    return 0;
}