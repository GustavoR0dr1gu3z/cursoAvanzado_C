#include <iostream>

using namespace std;

int main(){

    int numero;

    cout<<"Digite un numero entre 0-9: "; cin>>numero;

    switch (numero)
    {
        case 1: cout<<"Numero 1"<<endl;  break;
        case 2: cout<<"Numero 2"<<endl;  break;
        case 3: cout<<"Numero 3"<<endl;  break;
        case 4: cout<<"Numero 4"<<endl;  break;
        case 5: cout<<"Numero 5"<<endl;  break;
        case 6: cout<<"Numero 6"<<endl;  break;
        case 7: cout<<"Numero 7"<<endl;  break;
        case 8: cout<<"Numero 8"<<endl;  break;
        case 9: cout<<"Numero 9"<<endl;  break;
        case 0: cout<<"Numero 0"<<endl;  break;        
    
    default:
        cout<<"Fuera del rango ya establecido"<<endl;
        break;
    }



    return 0;
}