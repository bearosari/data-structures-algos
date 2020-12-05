#include <iostream>

using namespace std;

int expo(int a, unsigned int b)
{
    if(b == 0){
        return 1;
    }
    if(b % 2 ==0){
            return expo(a, b/2) *expo( a, b/2);
    }
    else{
        return a*expo(a, b/2) *expo( a, b/2);
    }
}

int main(){
    int a, b;
    cout << "Enter base: " << endl;
    cin >> a;
    cout << "Enter exponent: " << endl;
    cin >> b;
    cout << "Answer is: " << expo(a,b) << endl;;
}