#include <iostream>

using namespace std;

void array_decl_init() {
    char cArray[5]; // {?, ?, ?, ?, ?}
    int iArray[] = {1, 2, 3, 'A', 'B', 'C'}; // {1, 2, 3, 65, 66, 67}
    double dArray[4] = {1.41, 2.71, 3.14}; // {1.41, 2.71, 3.14, 0}
    cout << "sizeof(cArray) = "
         << sizeof(cArray) << '\n'; //5*sizeof(char)
    cout << "sizeof(iArray) = "
         << sizeof(iArray) << '\n'; //4*sizeof(int)
    cout << "sizeof(dArray) = "
         << sizeof(dArray) << endl; //4*sizeof(double)
    
    for(unsigned int i = 0; i < sizeof(cArray)/sizeof(char); ++i) {
        cout << "(int)cArray[" << i << "] =  " << int(cArray[i]) << endl;
    }

    for(unsigned int i = 0; i < sizeof(iArray)/sizeof(int); ++i) {
        cout << "iArray[" << i << "] = " << iArray[i] << endl;
    }

    for(unsigned int i = 0; i < sizeof(dArray)/sizeof(double); ++i) {
        cout << "dArray[" << i << "] = " << dArray[i] << endl;
    }
}

void array_access() {
    const unsigned int ARRAY_SIZE = 10;
    int iArray[ARRAY_SIZE];
    iArray[0] = 0;
    iArray[1] = 1; 
    for(unsigned int i = 2; i < ARRAY_SIZE; ++i) {
        iArray[i] = iArray[i-2] + iArray[i-1];
    }
    for(unsigned int i = 0; i < ARRAY_SIZE; ++i) {
        cout << "iArray[" << i << "] = " << iArray[i] << endl;
    }
}

void arrays_2d() {
    int iArr1[5] = {4, 3, 5, 1};
    int iArr2[5] = {6, 2, 3, 9};

    for(unsigned int i = 2; i < ARRAY_SIZE; ++i) {
        iArray[i] = iArray[i-2] + iArray[i-1];
    }    
}

int main() {
    array_decl_init();
    array_access();
    arrays_2d();
}