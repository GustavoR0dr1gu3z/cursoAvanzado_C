#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int i,j,pr;
    const char *sp;

    sp = omp_get_nested()? "Soportado":"No Soportado";
    cout<<"Paralelismo Anidado es: "<<sp<<endl;

    #pragma omp parallel for num_threads(2)
    {
        for(i=0; i<20;i++){
            cout<<"Hilo Trabajando "<<omp_get_thread_num()<<endl;
        }
    }


}