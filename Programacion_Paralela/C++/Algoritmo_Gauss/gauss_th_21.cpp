#include <iostream>
#include <fstream>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;
float *X, **Au, tm; //tm = tiempo, vector = X, matriz Aumentada = Au
int ren, col, m;

struct parms{ //Estructura de los parametros
    int a, b, c;
    float *w1, *w2, **M; //Vector w1, w2, y Matriz M
};

//Funciones
float** crea_mat(int, int);
float* crea_vect(int);
int muestra_mat(float**, int, int);
int muestra_vect(float*, int);
void* mult_hilo(void*);
float** lee_mat(char*, int, int);
float* lee_vect(char*, int);
float* eval_ret(float**, int, int); //vector solucion
int guarda_mat(float**, int, int, char*);

int main(int argc, char*argv[]){
    int i, j, ren, col, hi; //Definimos algunos indices
    unsigned start, stop;

    ren = atoi(argv[1]); //Renglones 1 argumento
    col = atoi(argv[2]); //Columnas  2 argumento
    pthread_t hilos[4];  //Se crean arreglo de 4 hilos

    struct parms hilos_arg[4]; // Estructuras de hilos

    char nvect[10] = "vecV.txt";
    char nmat[10] = "matV.txt";
    char nmatsol[12] = "matXsol.txt";
// Asignando memoria a las funciones
    X = crea_vect(ren);
    Au = crea_mat(ren, col);
    Au = lee_mat(nmat,ren,col);
    muestra_mat(Au,ren,col);

    start=clock(); // Tiempo
    for(i=0; i<ren-1; i++){ // Renglones que actualizan
        for(j=i+1; j<ren; j++){ // Columnas, que van hasta el renglon
            hi = j%4; // Renglones que trabajaremos
            hilos_arg[hi].w1 = Au[i]; // Renglon i, para todos i
            hilos_arg[hi].w2 = Au[j]; // Renglon i, para todos j
            hilos_arg[hi].M = Au;     // Matriz del sistema aumentada
            hilos_arg[hi].a = col;    // Columnas 
            hilos_arg[hi].b = i;      // Renglon i
            hilos_arg[hi].c = j;      // Renglon j

            // Hilos a ejecutar        
            pthread_create(&hilos[hi], NULL, &mult_hilo, &hilos_arg[hi]);
            // 
            pthread_join(hilos[hi], NULL);
        }
    }
    // 2 etapa, evaluacion retroactiva
    X = eval_ret(Au, ren, col);
    // Detenemos el reloj
    stop = clock();

    tm = (double(stop-start/CLOCKS_PER_SEC));
    cout<<"Tiempo de ejecucion: "<<tm<<"segundos"<<endl;

    // Muestra el vector
    muestra_vect(X,ren);
    // muestra_mat(Au,ren,col);
    return 0;
}
//--------------------------------------------------------------MULTI HILO------------------------------------------------------------

void* mult_hilo(void* parameters){
    struct parms* p=(struct parms*) parameters;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    int i,j,k,col;
    float mg = 0;
    col = p -> a;
    i = p -> b;
    j = p -> c;

    mg = (p-> M[p->c][p->b])/(p->M[p->b][p->b]);
    for(k=0; k<col; k++){
        pthread_mutex_lock(&mtx);
        p->M[j][k] = p->w2[k]-mg*(p->w1[k]);
        pthread_mutex_unlock(&mtx);
    }
return NULL;
}
//--------------------------------------------------------------MATRIZ----------------------------------------------------------------
//----------------------------CREA LA MATRIZ----------
float** crea_mat(int m, int n){
    int j;
    float **M;
    M = new float*[m]; // Arreglo a M de m elementos

    for(j=0; j<m; j++){
        M[j] = new float[n]; // Le asignamos a ese arreglo las columnas
    }
    return M;
}

//-----------------------------LEE LA MATRIZ------------
float** lee_mat(char *nom_arch, int m, int n){
    int i, j;
    float **M;
    M = crea_mat(m,n);
    fstream fd1;
    fd1.open(nom_arch, ios::in);
    while(!fd1.eof()){
        int i, j;
        for(i=0;i<m;i++){
            for (j=0;j<n;j++){
                fd1>>M[i][j];
            }
            
        }
    }
    fd1.close();
    cout<<"Matriz Leida"<<endl;
    return M;
}


//--------------------GUARDA LA MATRIZ------------------

int guarda_mat(float** A, int r, int c, char* nom_arch){
    int i, j;
    fstream fd1;
    fd1.open(nom_arch, ios::out);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            fd1<<A[i][j]<<" ";
        }
        cout<<endl;
    }
fd1.close();
cout<<"Matriz Guardada"<<endl;
return 0;
}

//-------------------------MUESTRA LA MATRIZ------------
int muestra_mat(float **M, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//--------------------------------------------------------------VECTOR----------------------------------------------------------------
//-------------------------CREA EL VECTOR---------------

float* crea_vec(int m){
    float *W;
    W = new float [m];      
    return W;
}

//-------------------------MUESTRA EL VECTOR-------------
int muestra_vec(float *M, int m){
    int j;
    for(j=0; j<m; j++){
        cout<<M[j]<<" ";
    }
    cout<<endl;
    return 0;
}

//----------------------------------------------------------------EVALUACION RETROACTIVA----------------------------------------------
float * eval_ret(float **A, int r, int c){
    int i, j, m, n;
    float *Y, S = 0;
    Y = crea_vect(r);
    Y[r-1] = A[r-1][c-1] / A[r-1][r-1];
    m = r-1;
    n = c-1;
    for(i=m;i>=0; i--){
        S = 0;
        for (j=m+1; j>= i+1; j--){
            S = S+(A[i][j]*Y[j]);
        }
        Y[i] = (A[i][c-1]-S)/A[i][i];
        S = 0;    
    }
return Y;
}
