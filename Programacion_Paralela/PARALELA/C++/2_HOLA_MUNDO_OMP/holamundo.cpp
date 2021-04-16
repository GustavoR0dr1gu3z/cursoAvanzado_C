#include <iostream>
#include <omp.h>

using namespace std;
int main(){

    #pragma omp parallel
    {
        cout<<"Hola Mundo En Paralelo"<<endl;
    }
    return 0;
}