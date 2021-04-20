// EJERCICIO 2

// Se compila con: g++ -o holaCompilado hola.cpp -fopenmp
// Se ejecuta con: ./holaCompilado

// ES PARA SABER CUANDOS HILOS OCUPARÉ

#include <iostream>
#include <omp.h>

using namespace std;
int main(){

// Definit un entero k para la suma
    int k = 0;

// Si quiero mas impresiones en pantalla
    omp_set_num_threads(6);

    // Definimos una región paralela
    #pragma omp parallel 
    {
        cout<<k<<endl; // Imprimir k
        k += 1;
        cout<<"Hola Mundo En Paralelo"<<endl;
        cout<<k<<endl; // Imprimir k
    }
    return 0;
}