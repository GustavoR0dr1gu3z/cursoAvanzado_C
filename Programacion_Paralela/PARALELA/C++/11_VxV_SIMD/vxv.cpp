#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include "func_omp.h"


using namespace std;

int vxv (float *a, float*b, int n){
    int i;
    #pragma omp simd reduction(+:c)
        for(i=0; i<n; i++){
            c = b[i]*a[i];
        }
return c;
}

int main(int argc, char *argv[]){
    float *a, *b, *c;
    int n;
    char *nomArc, *nomArc2;
    n= atoi(argv[1]);
    nomArc = argv[2];
    nomArc2 = argv[3];

    #pragma omp sections
    {
        #pragma omp section
        {
            a = crea_vec(n);
            a = lee_vec(nomArc,n);
        }
        #pragma omp section
        {
            b = crea_vec(n);
            b = lee_vec(nomArc,n);
        }
    }

cout<<"Resultado: "<<c<<endl;
return 0;
}