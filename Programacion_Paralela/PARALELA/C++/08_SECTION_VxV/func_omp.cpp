#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

float* lee_vec(char*, int);
float* crea_vec(int);
int muestra_vec(float*, int);



float* crea_vec(int m){
    float *W;
    W = new float [m];      
    return W;
}


int muestra_vec(float *M, int m){
    int j;
    for(j=0; j<m; j++){
        cout<<M[j]<<" ";
    }
    cout<<endl;
    return 0;
}

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