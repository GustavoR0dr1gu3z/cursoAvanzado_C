#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int i,j,pr;
    const char *sp;

    sp = omp_get_nested()? "Soportado":"No Soportado";
    cout<<"Paralelismo Anidado es: "<<sp<<endl;

    #pragma omp parallel


}