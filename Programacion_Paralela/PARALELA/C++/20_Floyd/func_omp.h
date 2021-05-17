float** crea_mat(int, int);
float* crea_vec(int);
int muestra_mat(float**, int, int);
int muestra_vec(float*, int);
void* mult_hilo(void*);
float prod_mm(float**, float**, int);
float** lee_mat(char* ,int ,int);
float* lee_vec(char*, int);
int ini_vect(float*,int);

float** crea_mat(int m, int n){
    int j;
    float** M;
    M = new float*[m];

    for(j=0; j<m; j++){
        M[j] = new float[n];
    }
return M;
}


int muestra_mat(float** M, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            cout<<M[i][j]<<", ";
        }
        cout<<endl;
    }
return 0;
}
