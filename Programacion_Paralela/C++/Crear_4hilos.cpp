#include <pthread.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

//Estructura de h1, leer archivo
struct read_file{
    int countR;
    string fraseR;
};

//Estructura de h2, escribir archivo
struct write_file {
    string fraseW;
    int countW;
};

//Estructura de h3, imprime en pantalla
struct print_phrase{
    string fraseP;
    int countP;
};

//Estructura de h4, genera numeros aleatorios
struct random_number{
    int numerosN;
    int countN;
};


// Metodo para leer archivo
void* leer_archivo(void* parametros){

struct read_file* r = (struct read_file*) parametros;
    
    int i;    
    for(i=0; i<r->countR;i++)
        {
            cout<<r->fraseR;
        }  
    return NULL;

}

// Metodo para escribir archivo
void* escribir_archivo(void* parametros){

struct write_file* w = (struct write_file*) parametros;
    
    int i;    
    for(i=0; i<w->countW;i++)
        {
            cout<<w->fraseW;
        }  
    return NULL;

}
// Metodo imprime el contenido en terminal
void* imprime_terminal(void* parametros){

struct print_phrase* p = (struct print_phrase*) parametros;
    
    int i;    
    for(i=0; i<p->countP;i++)
        {
            cout<<p->fraseP;
        }  
    return NULL;

}
// Metodo para leer archivo
void* numeros_aleatorios(void* parametros){

struct random_number* n = (struct random_number*) parametros;
    
    int i;    
    for(i=0; i<n->countN;i++)
        {
            cout<<n->numerosN;
        }  
    return NULL;

}

int main(){

    int numero, c;
    srand(time(NULL));

    numero = 1+rand()%(11-1);

    pthread_t t1;
    pthread_t t2;    
    pthread_t t3;    
    pthread_t t4;    

    struct read_file t1_args;
    struct write_file t2_args;
    struct print_phrase t3_args;
    struct random_number t4_args;

    t1_args.fraseR = 'Leyendoooooo';
    t1_args.countR = 10000;
    pthread_create(&t1,NULL,&leer_archivo,&t1_args);

    t2_args.fraseW = 'Escribiendoooo ';
    t2_args.countW = 10000;
    pthread_create(&t2,NULL,&escribir_archivo,&t2_args);

// Listo
    t3_args.fraseP = 'Hola Hilos ';
    t3_args.countP = 10000;
    pthread_create(&t3,NULL,&imprime_terminal,&t3_args);
// Listo
    t4_args.numerosN = numero;
    t4_args.countN = 10000;
    pthread_create(&t4,NULL,&numeros_aleatorios,&t4_args);


    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);


    return 0;
}






