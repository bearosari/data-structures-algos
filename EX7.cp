#include <iostream>

using namespace std;

void rec(int N){
    if(N==1){
        cout << 1 << endl;
    }
    else{
        cout << N <<endl;
        (rec(N-1));
        cout << N << endl;
    }
}

int main(){
    int a;
    cout << "Enter N: ";
    cin >> a;
    rec(a);
}
