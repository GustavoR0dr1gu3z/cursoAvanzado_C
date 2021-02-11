#include <iostream>
#include <math.h>

using namespace std;

int main(){

    float a,b,c,x1=0.0,x2=0.0;

    cout<<"Digite el valor de ax2: "; cin>>a;
    cout<<"Digite el valor de bx: "; cin>>b;
    cout<<"Digite el valor de c: "; cin>>c;

    x1 = ( (-b+sqrt((pow(b,2))-(4*a*c)) ) / (2*a) );
    x2 = ( (-b-sqrt((pow(b,2))-(4*a*c)) ) / (2*a) );    

    cout<<"\nx1: "<<x1<<endl;
    cout<<"x2: "<<x2<<endl<<endl;

    return 0;
}