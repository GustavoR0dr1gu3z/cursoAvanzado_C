#include <iostream>

using namespace std;

int main(){

    float a,b,c,d,e,f, res = 0;

    cout<<"Digite valor de a: "; cin>>a;
    cout<<"Digite valor de b: "; cin>>b;
    cout<<"Digite valor de c: "; cin>>c;
    cout<<"Digite valor de d: "; cin>>d;
    cout<<"Digite valor de e: "; cin>>e;
    cout<<"Digite valor de f: "; cin>>f;

    res = (((a)+(b/c))/((d)+(e/f)));

    cout<<"\nEl resultado es: "<<res<<endl<<endl;

    return 0;
}