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

int main(){





return 0;
}

