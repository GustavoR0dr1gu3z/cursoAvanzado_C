#ifndef gauss_fun212_h
#define gauss_fun212_h

using namespace std;
float** crea_mat(int, int);
float* crea_vect(int);
int muestra_mat(float**, int, int);
int muestra_vect(float*, int);
void* mult_hilo(void*);
float** lee_mat(char*, int, int);
float* lee_vect(char*, int);
int ini_vect(float*, int);
float* eval_ret(float**, int, int);
int guarda_mat(float**, int, int, char*);

#endif