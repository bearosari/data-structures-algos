#include <iostream>

using namespace std;

void pointer_basics() {
    int iVar = 10;
    int *iPtr = &iVar;
    cout << "iPtr : " << iPtr << endl;
    cout << "*iPtr : " << *iPtr << endl;//
    cout << "iVar : " << iVar << endl;
    cout << "&iVar : " << &iVar << endl;
    cout << "sizeof(iPtr) = " << sizeof(iPtr) << endl;
    char *cPtr = (char *)0x60000004;
    cout << "cPtr : " << cPtr << endl;    
}

void memory_alloc() {
    double *dPtr = new double[3];
    double dArr[3];
    dPtr[0] = 1.414;
    *(dPtr + 1) = 3.141;
    dArr[0] = 1.414;
    *(dArr+1) = 3.141;
    cout << "dPtr[0] = " << dPtr[0] << endl;
    cout << "*(dPtr + 1) = " << *(dPtr + 1) << endl;
    cout << "dArr[0] = " << dArr[0] << endl;
    cout << "*(dArr + 1) = " << *(dArr + 1) << endl;
}

int main() {
    //pointer_basics();
    memory_alloc();
}