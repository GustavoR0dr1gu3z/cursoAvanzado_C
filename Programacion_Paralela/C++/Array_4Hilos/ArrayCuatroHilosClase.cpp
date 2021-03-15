#include <pthread.h>
#include <cstdio>
#include <iostream>

using namespace std;

struct char_print_parms{
    char caracter;
    int count;
};

void * char_print(void* parameters){
    struct char_print_parms* p=(struct char_print_parms*) parameters;
    int i;
    for (i = 0; i < (p->count) ; i++){
        cout<< p->caracter;    
    }
        return NULL;
}

int main(){

    // Declaro un arreglo de hilos
    pthread_t hilos[4];

    struct char_print_parms hilos_args[4];

    hilos_args[0].caracter = 'x';
    hilos_args[0].count = 10000;
    pthread_create(&hilos[0], NULL, &char_print, &hilos_args[0]);

    hilos_args[2].caracter = 'o';
    hilos_args[2].count = 10000;
    pthread_create(&hilos[2], NULL, &char_print, &hilos_args[2]);

    hilos_args[3].caracter = 'y';
    hilos_args[3].count = 10000;
    pthread_create(&hilos[3], NULL, &char_print, &hilos_args[3]);

    hilos_args[1].caracter = '-';
    hilos_args[1].count = 10000;
    pthread_create(&hilos[1], NULL, &char_print, &hilos_args[1]);


    pthread_join(hilos[1], NULL);
    pthread_join(hilos[2], NULL);
    pthread_join(hilos[3], NULL);
    pthread_join(hilos[0], NULL);

    return 0;
    pthread_exit(NULL);

}