#include <iostream>
using namespace std;

int sumArr(int arr[][3],int r, int c){
    int sum= 0;
    for(unsigned int i=0; i<r; ++i){
    for(unsigned int j=0; j<c; ++j){
        sum+=arr[i][j];
    }

}
return sum;
}
int main(){
    int a[4][3]= {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    cout<< sumArr(a,4, 3) << endl;
}