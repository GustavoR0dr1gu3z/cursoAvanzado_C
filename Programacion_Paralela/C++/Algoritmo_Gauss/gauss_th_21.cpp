#include <iostream>
#include <fstream>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;
float *X, **Au, tm;
int ren, col, m;

struct parms{
int a, b, c;
float *w1, *w2, **M;
};

float** crea_mat(int, int);
float* crea_vect(int);
int muestra_mat(float**, int, int);
int muestra_vect(float*, int);
void* mult_hilo(void*);
float** lee_mat(char*, int, int);
float* lee_vect(char*, int);
int ini_vect(float*, int);
float* eval_ret(float**, int, int);
int guarda_mat(float**, int, int, char*);

int main(int argc, char*argv[]){
    int i, j, ren, col, hi;
    unsigned start, stop;

    ren = atoi(argv[1]);
    col = atoi(argv[2]);
    pthread_t hilos[4];

    struct parms hilos_arg[4];

    char nvect[10] = "vecV.txt";
    char nmat[10] = "matV.txt";
    char nmatsol[12] = "matXsol.txt";

    X = crea_vect(ren);
    Au = lee_mat(nmat,ren,col);
    muestra_mat(Au,ren,col);




}