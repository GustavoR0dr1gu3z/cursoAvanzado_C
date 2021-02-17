#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

        char a[128];
        ifstream file;
        file.open("file.txt");
        
        while(!file.eof()){
            file >> a;
            cout << a <<endl;
        }
        file.close();

    return 0;
}