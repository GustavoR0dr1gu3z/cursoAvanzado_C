
#include <thread>  //Para crear el Hilo
#include <iostream>  //Flujo de entrada y salida
#include <fstream>  //Manejo de archivos

using namespace std;



//Funcion para el hilo
void funcionCreada(){
    //Crea un archivo llamado hiloUno.txt y lo cierra de manera correcta
    ofstream salidaArchivo("hiloUno.txt");
    
    salidaArchivo <<"Este es el texto que irá dentro del archivo"<<endl;   
    
    salidaArchivo.close();
}



int main(){

    //Creando hilo
    //Cuando se crea hilo se manda a llamar una funcion (funcionCreada)
    thread hiloUno (funcionCreada);

    //Para que termine correctamente el programa
    hiloUno.join();    


    return 0;
}
