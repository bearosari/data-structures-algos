//BEA ROSARI B SUPANGA
//2018-10282

#include <iostream>
using namespace std;

int main()
{
    int num=0;
    cout << "Enter a 2 digit number: ";
    cin >> num;
    //inputs a 2 digit number
    while (num>99 || num<10 || cin.fail()) {
        // error handling if an input is not a 2 digit number 
        // and when it's not an integer at all
        cout << "That's not a 2 digit number. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        //clears out the original value of num
        cin >> num;
    }

    for (int x=1; x<num; x++){
        //autoincrements from 1 up to the input number
        if (x%9==0){
            //checking diviibility by 9
            cout << x << endl;
        }
    }
    
    
}