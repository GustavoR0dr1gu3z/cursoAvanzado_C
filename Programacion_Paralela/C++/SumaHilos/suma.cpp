// Se compila con: g++ -o sumaCompilado suma.cpp
// Se ejecuta con: ./sumaCompilado 1 2 3

#include <iostream>
#include <stdlib.h>

using namespace std;

//argc = Rencuentro de argumentos
//argv = vector de argumentos
int main(int argc, char *argv[]){
    int suma = 0;
    int a,b,c;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    suma = a+b+c;

    cout<<"La suma de los " <<argc-1<<" sumandos es: "<<endl;
    cout<<suma<<endl;    
    
    return 0;
}