// EJERCICIO 7

// Hecho por: Gustavo Rodriguez Calzada
// El dia: 23 de Abril de 2021

// SE COMPILA COMO: g++ -o dsCompilado ds.cpp -fopenmp
// SE EJECUTA COMO: ./dsCompilado


#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int nth, tid;
    #pragma omp parallel private(tid)
        #pragma omp sections
        {
            #pragma omp section
            {
                tid = omp_get_thread_num();
                nth = omp_get_num_threads();
                cout<<"El hilo: "<<tid<<" Calcula la seccion 1 de: "<<nth<<endl;
            }
            #pragma omp section
            {
                tid = omp_get_thread_num();
                nth = omp_get_num_threads();
                cout<<"El hilo: "<<tid<<" Calcula la seccion 2 de: "<<nth<<endl;                
            }
            #pragma omp section
            {
                tid = omp_get_thread_num();
                nth = omp_get_num_threads();
                cout<<"El hilo: "<<tid<<" Calcula la seccion 3 de: "<<nth<<endl;                
            }            
            #pragma omp section
            {
                tid = omp_get_thread_num();
                nth = omp_get_num_threads();
                cout<<"El hilo: "<<tid<<" Calcula la seccion 1 de: "<<nth<<endl;
                
            }
        }
        return 0;
}