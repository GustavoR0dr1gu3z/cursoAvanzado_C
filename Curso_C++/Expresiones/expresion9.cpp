#include <iostream>
#include <math.h>

using namespace std;

int main(){

    float x,y,res=0.0;

    cout<<"Digite el valor de X: "; cin>>x;
    cout<<"Digite el valor de Y: "; cin>>y;

    res = (  (sqrt(x)) / ((pow(y,2))-1)  );

    cout<<"\nEl resultado es: "<<res<<endl<<endl;


    return 0;
}