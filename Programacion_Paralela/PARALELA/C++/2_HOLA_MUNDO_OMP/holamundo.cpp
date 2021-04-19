// EJERCICIO 2

// Se compila con: g++ -o holamundoCompilado holamundo.cpp -fopenmp
// Se ejecuta con: ./holamundoCompilado

#include <iostream>
#include <omp.h>

using namespace std;
int main(){
    
// Definit un entero k para la suma
    int k = 0;

// Si quiero mas impresiones en pantalla
    omp_set_num_threads(10);
    #pragma omp parallel
    {
        cout<<k<<endl; // Imprimir k
        k += 1;
        cout<<"Hola Mundo En Paralelo"<<endl;
        cout<<k<<endl; // Imprimir k

    }
    return 0;
}