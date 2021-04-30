#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <omp.h>
#include "fun_omp.h"

void simd_loop(float *a, float *b, float *c, int n){
    int i;
    #pragma omp simd
        for (i=0; i<n; i++){
            a[i] = b[i]+c[i];
        }
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
            a = lee_vect(nomArc,n);
        }
        #pragma omp section
        {
            b = crea_vec(n);
            b = lee_vec(nomArc,n);
        }
        #pragma omp section
        {
            c = crea_vec(n);
            c = lee_vec(nomArc,n);
        }
    }


return 0;
}

