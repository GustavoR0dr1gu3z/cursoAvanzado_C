#include <iostream>
#include <fstream>
#include <pthread.h>
#include <time.h>


using namespace std;

float z, *V, *U;
int m;

struct parms{
    int a;
    int b;
};

void* prod(void *);
float* lee_vec(char *,int);

int main(int argc, char *argv[]){
    int i;
    clock_t tm;

    m = atoi(argv[1]);
    pthread_t hilos[4];
    struct parms hilos_arg[4];

    clock_t start, stop;

    char nvect1[10] = "vectU.dat";
    char nvect2[10] = "vectV.dat";


    V = new float[m];
    U = new float[m];

    U = lee_vec(nvect1,m);
    V = lee_vec(nvect2,m);

    start = clock();

    for(int i=0;i<4;i++){
        hilos_arg[i].a = i*250;
        hilos_arg[i].b = (i*250)+249;
        pthread_create(&hilos[i], NULL, &prod, &hilos_arg[i]);
        pthread_join(hilos[i], NULL);
    }

    stop = clock();

    // CLOCKS_PER_SECOND
tm = stop-start;

cout<<"El producto es: "<<z<<endl;
cout<<"Tiempo de ejecucion: "<<tm<<endl;
return 0;
}



void* producto(void* parameters){

    struct parms* p = (struct parms*) parameters;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

    int x,y,c,i;

    x = p->a;
    y = p->b;
    c=0;

    pthread_mutex_unlock(&mtx);}

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



