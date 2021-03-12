#include <iostream>
#include <fstream>
#include <pthread.h>
#include <time.h>

using namespace std;

pthread_t hilos[4];
struct parms hilos_args[4];
float **A;
float *V, *W;

float** crea_mat(int, int);
float* crea_vec(int);
int muestra_mat(float**, int, int);
int muestra_vec(float*, int);
void* mult_hilo(void*);
float prod_vv(float*, float*, int);
float** lee_mat(char* ,int ,int);
float* lee_vec(char*, int);
int ini_vect(float*,int);

int main(int argc, char* argv[]){
int i,k,hi;
int ren = atoi(argv[1]);
int col = atoi(argv[2]);
char nomMat[13] = "matA.txt";
char nomVect[10] = "unos.txt";

A = crea_mat(ren,col);
A = lee_mat(nomMat, ren, col);
V = crea_vec(col);
V = lee_vec(nomVect, ren);
cout<<endl;
muestra_mat(A, ren, col);
cout<<endl;
for (i = 0; i < ren; i++){
        hi = i%4;
        hilos_args[hi].w1 = A[i];
        hilos_args[hi].w2 = v;
        hilos_args[hi].cols = col;
        hilos_args[hi].inic = i;
        pthread_create(&hilos[hi], NULL, &mult_hilo, &hilos_args[hi]);
        pthread_join(hilos[hi], NULL);
}
muestra_vec(w,ren);
pthread_exit(NULL);
return 0;
}

float* lee_vec(char *nom_arch, int m){
    int i;
    float* W;
    cout<<"Leyendo Vector"<<endl;

    W = crea_vec(m);
    fstream fd2;
    fd2.open(nom_arch, ios::in);
    while(!fd2.eof()){
        int i, j;
            for(i=0; i<m; i++){
                fd2>>W[i];
            }
    }
    fd2.close();
    cout<<"Vector Leido"<<endl;
return W;
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

float* crea_vec(int m){
    float* W;
    W = new float[m];
return W;
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

int muestra_vec(float *M, int n{
    int j;
    for(j=0; j<n; j++){
        cout<<M[j]<<", ";
    }
    cout<<endl;
return 0;
}

float prod_vv(float * V, float *U, int n){
    int j;
    float W = 0;
    for(j=0; j<n; j++){
        W = W + V[j]*U[j];
    }
return W;    
}


void* mult_hilo(void* parameters){
    struct parms* p=(struct parms*) parameters;
    int i, k;
    i = p->inic;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&mtx);
        w[i] = prod_vv(p->w1, p->w2, p->cols);
    pthread_mutex_unlock(&tmx);
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




