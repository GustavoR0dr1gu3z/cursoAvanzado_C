#include <iostream>
#include <fstream>

using namespace std;


int main(){

    string filename("file2.txt");
    fstream archivo_salida;
    archivo_salida.open(filename);

    if(!archivo_salida.is_open()){
        cout<<"No se puede abrir el archivo "<<filename<<endl;        
    }else{
        archivo_salida<<"Archivo "<<endl;
        cout<<"Terminal"<<endl;
    }
    archivo_salida.close();

    return 0;
}