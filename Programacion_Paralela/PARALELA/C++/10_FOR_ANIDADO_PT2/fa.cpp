#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int i,j,pr;
    const char *sp;
    omp_set_nested(true);
    sp = omp_get_nested()? "Soportado":"No Soportado";
    cout<<"Paralelismo Anidado es: "<<sp<<endl;

    #pragma omp parallel for num_threads(2)
    {
        for(i=0; i<20;i++){
            cout<<"Hilo Trabajando "<<omp_get_thread_num()<<endl;            
            for(j=0; j<4; j++){
                pr = i+j;
                cout<<"Producto Anidado Interno: "<<pr<<endl;
            }
        }    
    }
return 0;
}