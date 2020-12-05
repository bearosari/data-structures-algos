#include <iostream>
#include <array>
using namespace std;


array<int,3> crossproduct(array<int,3> x, array<int,3> y){

    int i= (x.at(1)*y.at(2) - x.at(2)*y.at(1));
    int j= (x.at(2)*y.at(0) - x.at(0)*y.at(2));
    int k= (x.at(0)*y.at(1) - x.at(1)*y.at(0));
    array <int, 3> z={i,j,k};
    return z;
}

int main() {
    array<int,3> x={2,3,4};
    array<int,3> y={5,6,7};
    array<int, 3> z={crossproduct(x,y)};
    for (unsigned int i=0; i <x.size(); ++i){
    cout << z.at(i) << endl;
}
}