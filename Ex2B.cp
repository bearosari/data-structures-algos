#include <iostream>
using namespace std;


int *foo(int size){
    int *iPtr= new int[size];
    return iPtr;
}
int main() {
    int *aPtr= foo(5);
    cout <<  aPtr << endl;
    delete[] aPtr;
}