//BEA ROSARI B SUPANGA
//2018-10282


#include <iostream>
#include <vector>
using namespace std;

int sum_divisors(int x) 
//function that computes sum of proper divisors
{
    int sum=0; 
    if (x>0){
        for (int i=1; i<=x/2; i++) {
            if (x%i == 0){
                //cout << i << endl;
                sum+=i;
            } 

        }
    }
    else{
        sum=0;
    }
    return sum;
}

int is_amicable(int a, int b){
    //function that tests if a number is a member of an amicable pair
    if(sum_divisors(a)==b && sum_divisors(b)==a && a!=b)
    {
        return true;
    }else 
    {
        return false;
    }
}


int sum_amicable(int n, int m){
    //computes the sum of amicable numbers from 1-n
    vector <int> amicables; 
    //creates a list of amicable numbers
    int sum=0;
    //const int n=10000;
    int i, j;
    for(int i=1; i<=n; i++)
    {
        j=sum_divisors(i);
        if (j<i){
            if(is_amicable(i,j)==true){
                //cout << i << " - " << j << endl;
                amicables.push_back(i); 
                //if the number is amicable it will be added to the list
                amicables.push_back(j);
                sum +=(i+j);
            }
        }       
    }
    if (find(amicables.begin(), amicables.end(), m) != amicables.end()== true){
        //looping through the amicable list finding out if the number is present
    cout << "Amicable!" << endl;
    //return true;
    }
    else{
    cout << "Not Amicable!" << endl;
    //return false;
    }
    cout << "<3> The sum of all amicable numbers from 1 to 10000 is: " << endl;
    return sum;
}


    //for (int m=0; m<amicables.size(); ++m)
    //cout << amicables[m] << ' ';
    
    

int main(){
    vector <int> amicables;
    int num1, num2, testnum;
    cout << "<1> Enter a number & find out the sum of its proper divisors: ";
    cin >> num1;
    cout << "The sum of its proper divisors is: " << sum_divisors(num1) << endl;
    cout << "<2> Enter a number to find out of it's amicable: ";
    cin >> testnum;
    cout << "Result: " << sum_amicable(10000, testnum) << endl;
    
}