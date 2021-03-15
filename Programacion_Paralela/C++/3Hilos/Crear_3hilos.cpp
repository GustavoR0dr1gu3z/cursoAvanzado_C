#include <pthread.h>
#include <cstdio>
#include <iostream>

using namespace std;

// Estructura de paso de datos de la función
struct print_parms {
    char caracter; // Caracter a imprimir
    int contador;
};

void* char_print(void* parameters){ 

struct print_parms* p = (struct print_parms*) parameters;

int i;
for (i = 0; i < p->contador; i++){ 
    cout<<p->caracter;
    
    }
    return NULL;
}

int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;

    struct print_parms t11_args;
    struct print_parms t22_args;
    struct print_parms t33_args;

    t11_args.caracter = 'x';
    t11_args.contador = 10000;
    pthread_create(&t1,NULL,&char_print,&t11_args);

    t22_args.caracter = 'y';
    t22_args.contador = 10000;
    pthread_create(&t2,NULL,&char_print,&t22_args);

    t33_args.caracter = 'z';
    t33_args.contador = 10000;
    pthread_create(&t3,NULL,&char_print,&t33_args);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

    return 0;

}