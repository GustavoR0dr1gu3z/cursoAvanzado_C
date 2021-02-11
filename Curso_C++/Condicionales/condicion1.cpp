#include <iostream>

using namespace std;

int main(){

    int digito = 10, num = 0;

    cout<<"Digite un numero para comparar: "; cin>>num;

    if(num == digito){
        cout<<"\nEl numero coincide"<<endl;
    }else{
        cout<<"\nEl numero NO coincide"<<endl;
    }


    return 0;
}