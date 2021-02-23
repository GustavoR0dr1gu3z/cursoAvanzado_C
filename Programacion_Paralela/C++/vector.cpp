//Caracteristicas: lscpu | egrep -i 'core.*:|socket'
//Se ejecuta: 
//Se compila:

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <time.h>

using namespace std;

float z, *V, *U; 

struct parms{
int a;
int b;
float *A;
float *B;
};

void* prod(void*);
float* lee_vec(char *, int);

int main(){

    int m = 1000;
    pthread_t hilos[4];

    struct parms hilos_arg[4];
    clock_t start, stop;

    char nvect1[10] = "vectU.txt"; 
    char nvect2[10] = "vectV.txt";

    V = new float[m];
    U = new float[m];

    U = lee_vec(nvect1,m);
    V = lee_vec(nvect2,m);

    start=clock();

    hilos_arg[0].a = 0;
    hilos_arg[0].b = 249;
    hilos_arg[0].A = U;
    hilos_arg[0].B = V;
    pthread_create(&hilos[0],NULL, &prod, &hilos_arg[0]);

    hilos_arg[1].a = 0;
    hilos_arg[1].b = 249;
    hilos_arg[1].A = U;
    hilos_arg[1].B = V;
    pthread_create(&hilos[1],NULL, &prod, &hilos_arg[1]);

    hilos_arg[2].a = 250;
    hilos_arg[2].b = 249;
    hilos_arg[2].A = U;
    hilos_arg[2].B = V;
    pthread_create(&hilos[2],NULL, &prod, &hilos_arg[2]);

    hilos_arg[3].a = 750;
    hilos_arg[3].b = 999;
    hilos_arg[3].A = U;
    hilos_arg[3].B = V;
    pthread_create(&hilos[3],NULL, &prod, &hilos_arg[3]);

    pthread_join(hilos[3],NULL);
    pthread_join(hilos[2],NULL);
    pthread_join(hilos[1],NULL);
    pthread_join(hilos[0],NULL);

    stop = clock();

    cout<<"El producto es: "<<z<<endl;
    cout<<"Tiempo de ejecucion"<<stop-start<<endl;

    return 0;
}


void* prod(void* parameters){

    struct parms* p = (struct parms*) parameters;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

    int x,y,c,i;
    float *C, *D;

    C = new float[1000];
    D = new float[1000];

    x = p->a;
    y = p->b;

    C = p->A;
    D = p->B;

    c=0;

    for(i=x;i<=y;i++){
        c+= C[i] * D[i];
    }

    pthread_mutex_unlock(&mtx);

    float* lee_vec(char *nom_arch, int m){
        float *W;
        W = new float[m];
        cout<<"Leyendo el vector "<<endl;
        fstream fd;
        fd.open(nom_arch, ios::in);
        
        while(!fd.eof()){
            int i;
            for(i=0; i<m; i++){
                fd>>W[i];
            }            
        }
        fd.close();
        cout<<"Vector Leido "<<endl;
        return W;
    }


}


