#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int i;
    //Private significa que cada hilo tendrá un cierto 
    //numero de indices que ejecutar dentro del for
    #pragma omp parallel for private(i)
        for (i =0; i<20; i++){
            cout<<"Hola mundo con omp: "<<i<<endl;
        }
}