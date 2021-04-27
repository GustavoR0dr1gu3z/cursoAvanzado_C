#include <omp.h>

using namespace std;

int main(){
    int i, j, pr;
    const char *sp;

    omp_set_nested(True);

    sp = omp_get_nested()? "Soportado":"No Soportado";
    cout<<"Paralelismo Anidado es: "<<sp<<endl;

    #pragma omp parallel num_threads(2)
    {
    cout<<"Thread: "<<omp_get_thread_num()<<" Ejecuta region exterior"<<endl;
    }
        




}