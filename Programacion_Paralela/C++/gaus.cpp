#include <iostream>
#include "gauss_fun212.h"

using namespace std;

float *X, **Au, **W, tm;


struct parms{
    int a,b,c;
    float *w1, *w2, **M;
};

int main(int argc, char *argv[]){
    int i,j,ren,col,hi;
    unsigned start, stop;

    ren = atoi(argc[1]);
    col = atoi(argv[2]);
    pthread_t hilos[4];

    struct patms hilos_arg[4];

    char nvect[10] = "vecV.dat";
    char nmat[10] = "matV.dat";
    char nmatsol[12] = "matXsol.dat";

    X = crea_vect(ren,col);
    Au = lee_mat(nmat,ren,col);
    muestra_mat(Au,ren,col);
    W = crea_mat(ren,col);
    W = lee_mat(nmat,ren,col);
    start=clock();

    for(i=0; i<ren; i++){
        for(j=i+1; j<ren; j++){
            hi = j%4;
            hilos_arg[hi].w1 = Au[i]
            hilos_arg[hi].w2 = Au[j]
            hilos_arg[hi].M = W;
            hilos_arg[hi].a = col;
            hilos_arg[hi].b = i;
            hilos_arg[hi].c = j;
            pthread_create(&hilos[hi],NULL, &mult_hilo, &hilos_arg[hi]);
            pthread_join(hilos[hi],NULL);
        }
    }

    stop = clock();
    tm = (double(stop-start)/CLOCKS_PER_SEC);

    cout<<"Tiempo de ejecución: "<<tm<<"segundos"<<endl;
    X = eval_ret(W,ren,col);
    guarda_mat(W,ren,col,nmatso);
    muestra_vect(X,ren);

return 0;
}

void* mult_hilo(void* parameters){
    struct parms* P=(struct parms*) parameters;
    pthread_mutex_t mtc = PTHREAD_MUTEX_INITIALIZER;
    int i,j,k,col;
    float *U, *V, **Q, mg = 0, uv = 0;
    col = p -> a;
    i = p -> b;
    j = p -> c;
    U = crea_vect(col); 
    V = crea_vect(col);
    Q = crea_mat(ren, col);
    U = p -> w1;
    V = p -> w2;
    Q = p -> M;

    mg = Q[j][i] / Q[i][j];
    for(k=0; k<col; k++){
        pthread_mutex_lock(&mtx);
        Q[j][k] = Q[j][k] - (mg*Q[j][k]);
        W[j][k] = Q[j][k];
        pthread_mutex_unlock(&mtx);
    }
return NULL;
}

flat** lee_mat(char *nom_arch, int m, int n){
    int i, j;
    float **M;
    M = crea_mat(m,n);
    fstream fd1;
    fd1.open(nom_arch, ios::in);
    while(!fd1.eof()){
        int i, j;
    }

}



float *eval_ret(float **A, int r, int c){
    int i, j, m, n;
    floa **M,  *Y, S=0;
    Y = crea_vect(r);
    Y[r-1] = A[r-1][c-1] / A[r-1][r-1];
    m = r-2;
    n = c-2;
    for(i=m;i>=0; i--){
        for (j=n; j>0; j--){
            S = S+(A[i][j]*Y[j]);
        }
    Y[i] = (A[i][c-1]-S)/A[i][i];
    S = 0;    
    }

return Y;
}

