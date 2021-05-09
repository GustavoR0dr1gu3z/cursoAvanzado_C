// EJERCICIO 2

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 20 de Abil de 2021

// Se compila con: g++ -o holaCompilado hola.cpp -fopenmp
// Se ejecuta con: ./holaCompilado

// ES PARA SABER CUANDOS HILOS OCUPARÉ

#include <iostream>
#include <omp.h>

using namespace std;
int main(){

// Si quiero mas impresiones en pantalla
    //omp_set_num_threads(6);

    // Definimos una región paralela
    #pragma omp parallel num_threads(4)
    {
        cout<<"Hola Mundo En Paralelo"<<endl;

    }
    return 0;
}