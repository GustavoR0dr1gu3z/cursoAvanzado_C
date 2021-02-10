#include <iostream>

using namespace std;

int main(){
    float cal1,cal2,cal3,cal4, promedio=0.0;

    cout<<"Digite la nota final de un alumno: "; cin>>cal1;
    cout<<"Digite la nota final de un alumno: "; cin>>cal2;
    cout<<"Digite la nota final de un alumno: "; cin>>cal3;
    cout<<"Digite la nota final de un alumno: "; cin>>cal4;

    promedio = ((cal1+cal2+cal3+cal4)/4);

    cout<<"La nota final media es: "<<promedio<<endl<<endl;

    return 0;
}