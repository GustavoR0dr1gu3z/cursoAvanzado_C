// EJEMPLO 9 

// Se compila como: g++ -o faCompilado fa.cpp -fopenmp
// Se ejecuta como: ./faCompilado

#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    int i, j, pr;
    const char *sp;

    omp_set_nested(true);

    sp = omp_get_nested()? "Soportado":"No Soportado";
    cout<<"Paralelismo Anidado es: "<<sp<<endl;

    #pragma omp parallel num_threads(2)
    {
    cout<<"Thread: "<<omp_get_thread_num()<<" Ejecuta region exterior"<<endl;
    }
    #pragma omp parallel num_threads(3)
    {
        cout<<"Thread: "<<omp_get_thread_num()<<" Ejecuta region interior"<<endl;
    }
return 0;
}