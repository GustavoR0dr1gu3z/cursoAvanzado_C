#include <iostream>

using namespace std;

int main(){

    int n1;
    float total=0;
    const float IVA=1.16;


    cout<<"Digite el precio del producto sin IVA: ";
    cin>>n1;

    total = (n1)*(IVA);

    cout<<"El precio del producto con IVA es: "<<total<<endl;



    return 0;
}