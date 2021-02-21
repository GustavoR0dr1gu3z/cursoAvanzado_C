// Se compila de esta manera: g++ -std=c++11 -o SumaParcialCompilado SumaParcial.cpp -lpthread
// Se ejecuta de esta manera: ./SumaParcialCompilado

#include <iostream>
#include <pthread.h>
#include <mutex>
#include <math.h>

using namespace std;

int z;
struct parms{
    int a;
    int b;
};

void* fun(void *parameters);

int main(int argc, char *argv[]){

// Arreglo de hilos     
    pthread_t th[4];
    
    struct parms th_args[4];

// Hilo 1
    th_args[0].a = 1;
    th_args[0].b = 99;
    pthread_create(&th[0], NULL, &fun,&th_args[0]);

// Hilo 2
    th_args[1].a = 100;
    th_args[1].b = 199;
    pthread_create(&th[1], NULL, &fun,&th_args[1]);

// Hilo 3
    th_args[2].a = 200;
    th_args[2].b = 299;
    pthread_create(&th[2], NULL, &fun,&th_args[2]);

// Hilo 4
    th_args[3].a = 300;
    th_args[3].b = 400;
    pthread_create(&th[3], NULL, &fun,&th_args[3]);

pthread_join(th[0],NULL);
pthread_join(th[1],NULL);
pthread_join(th[2],NULL);
pthread_join(th[3],NULL);
cout<<z<<endl;


return 0;
}

void* fun(void *parameters){
    struct parms* p = (struct parms*) parameters; //Casting para la funcion de hacer suma
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; // MUTEX es una forma de inicializarlo
        int x,y,c,i;
        x = p->a; // Se teclean estas variables, para contener la suma parcial
        y = p->b;
        c = 0;
        for(i=x; i<=y;i++){ 
            c +=i; // Se incrementa el valor
        }
        pthread_mutex_lock(&mtx); //Bloquea el manejador del MUTEX
            z = z+c;

        pthread_mutex_unlock(&mtx); //Desbloque el MUTEX para que otro hilo que estaba esperando, pueda entrar y hacer su suma parcial
    return NULL;
}