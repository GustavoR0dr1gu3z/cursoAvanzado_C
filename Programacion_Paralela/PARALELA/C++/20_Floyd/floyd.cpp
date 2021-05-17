#include <iostream>
#include <omp.h>
#include <stdlib.h>
#include "func_omp.h"

using namespace std;

float **A, **B;

int main(int argc, char* argv[]){
    int i,k,hi;
    int ren = atoi(argv[1]);
    int col = atoi(argv[2]);
    char nomMat[13] = "matA.txt";
    char nomMatB[13] = "matB.txt";


// SECTIONS: LEER Y MOSTRAR MATRIZ
    //#pragma omp parallel private(tid)
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            A = crea_mat(ren, col);
            A = lee_mat(nomMat, ren, col);
        }
        #pragma omp section 
        {        
            B = crea_mat(ren, col);
            B = lee_mat(nomMatB, ren, col);
        }
    }



}