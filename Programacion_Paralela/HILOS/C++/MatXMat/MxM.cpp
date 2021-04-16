//Se compila:  g++ -o MxMCompilado MxM.cpp -lpthread
//Se ejecuta: ./MxMCompilado 10 10

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <time.h>

using namespace std;

float **A, **B, **R;
float *W, *V;

struct parms{
    int a, b, c;
    float *w1, *w2, **Ma, **Mb, **M, cols, inic, rens, fin;
};

float** crea_mat(int, int);
float* crea_vec(int);
int muestra_mat(float**, int, int);
int muestra_vec(float*, int);
void* mult_hilo(void*);
float prod_mm(float**, float**, int);
float** lee_mat(char* ,int ,int);
float* lee_vec(char*, int);
int ini_vect(float*,int);

int main(int argc, char* argv[]){
    int i,k,hi;
    int ren = atoi(argv[1]);
    int col = atoi(argv[2]);
    char nomMat[13] = "matA.txt";
    char nomMatB[13] = "matB.txt";

    pthread_t hilos[4];
    struct parms hilos_args[4];

    A = crea_mat(ren, col);
    A = lee_mat(nomMat, ren, col);
    B = crea_mat(ren, col);
    B = lee_mat(nomMatB, ren, col);
    cout<<endl;
    muestra_mat(A, ren, col);
    cout<<endl;
    cout<<endl;
    muestra_mat(B, ren, col);
    cout<<endl;
    for (i = 0; i < ren; i++){
        hi = i%4;
        hilos_args[hi].w1 = A[i];
        hilos_args[hi].w2 = B[i];
        hilos_args[hi].rens = ren;
        hilos_args[hi].cols = col;
        hilos_args[hi].inic = i;
    
        pthread_create(&hilos[hi], NULL, &mult_hilo, &hilos_args[hi]);
        pthread_join(hilos[hi], NULL);
    }
    cout<<"Resultado: "<<endl;
    muestra_mat(R, ren, col);
    pthread_exit(NULL);
    return 0;
}


float** crea_mat(int m, int n){
    int j;
    float** M;
    M = new float*[m];

    for(j=0; j<m; j++){
        M[j] = new float[n];
    }
return M;
}


int muestra_mat(float** M, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<M[i][j]<<", ";
        }
        cout<<endl;
    }
return 0;
}



float prod_mm(float **V, float **U, int m){
    int i, j;
    float W=0;
    int n = m;
    for(i = 0; i<m; i++){
        for(j=0; j<n; j++){
            W += U[i][j] * V[j][j];
        }
    }
return W;    
}


void* mult_hilo(void* parameters){
    struct parms* p =(struct parms*) parameters;
    int i, j, k;
    i = p->inic;
    k = p->cols;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mtx);
    for(j=0; j<k; j++){
        R[i][j] = prod_mm(p->Ma, B, p->cols);
    }
    pthread_mutex_unlock(&mtx);
return NULL;
}

float** lee_mat(char *nom_arch, int m, int n){
    int i, j;
    float **M;
    M = crea_mat(m, n);
    fstream fd1;
    fd1.open(nom_arch, ios::in);
    while(!fd1.eof()){
        int i, j;
        for (i=0; i<m; i++){
            for (j=0; j<n; j++){
                fd1>>M[i][j];
            }
        }
    }
    fd1.close();
    cout<<"Matriz Leida"<<endl;
return M;
}




