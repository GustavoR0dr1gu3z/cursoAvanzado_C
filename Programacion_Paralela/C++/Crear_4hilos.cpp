#include <pthread.h>
#include <cstdio>
#include <iostream>
#include <fstream>


using namespace std;

//Estructura de h1, leer archivo
struct read_file{
    int countR;
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
            cout<<"ARCHIVO LEIDO";
        }  
    return NULL;

}

// Metodo para escribir archivo
void* escribir_archivo(void* parametros){

struct write_file* w = (struct write_file*) parametros;
    
    int i;    
    for(i=0; i<w->countW;i++)
        {
            cout<<"ARCHIVO ESCRITO";
        }  
    return NULL;

}
// Metodo imprime el contenido en terminal
void* imprime_Terminal(void* parametros){

struct print_phrase* p = (struct print_phrase*) parametros;
    
    int i;    
    for(i=0; i<p->countP;i++)
        {
            cout<<"Frase Mostrada";
        }  
    return NULL;

}
// Metodo para leer archivo
void* numerosAleatorios(void* parametros){

struct random_number* n = (struct random_number*) parametros;
    
    int i;    
    for(i=0; i<n->countN;i++)
        {
            cout<<"Frase leída";
        }  
    return NULL;

}







