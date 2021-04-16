// EJERCICIO 2

// Se compila con: g++ -o holamundoCompilado holamundo.cpp -fopenmp
// Se ejecuta con: ./holamundoCompilado

#include <iostream>
#include <omp.h>

using namespace std;
int main(){
// Si quiero mas 
    omp_set_num_threads(10);
    #pragma omp parallel
    {
        cout<<"Hola Mundo En Paralelo"<<endl;
    }
    return 0;
}