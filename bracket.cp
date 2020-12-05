
#include<iostream>
#include<string>
#include<stack>
#include <iostream>
#include <fstream>
using namespace std; 
  
bool bracket(string text) 
{ 
    stack<char> stack; 
    char symbol; 
  
   
        if (c=='('||c=='['||c=='{') 
        { 
            stack.push(c]); 
            continue; 
        } 

        if (stack.empty()) 
           return false; 
  
        switch(text[i])
        {
        case ')':

            symbol = stack.top(); 
            stack.pop(); 
            if (symbol=='{' || symbol=='[') 
                return false; 
            break; 
        

        case '}': 
  
            symbol = stack.top(); 
            stack.pop(); 
            if (symbol=='(' || symbol=='[') 
                return false; 
            break; 
        
        case ']':
  
            symbol = stack.top(); 
            stack.pop(); 
            if (symbol =='(' || symbol == '{') 
                return false; 
            break; 

        default:
            return true;

        } 
    }
  
    return (stack.empty()); 
} 
  
  
int main() {
    std::fstream infile("input_ex9.txt", std::ios::in);
    stack<char> asd;
    char c = ' ';
    while(true) {
        c = infile.get();
        // process current character (type: char)
        if(infile.eof()) {break;}   // when no more character can be read, value read is -1 which is End-Of-File (EOF)
        bracket(c);
    }
    std::cout << '\n';

    if (bracket(para)) 
        cout << "No Error" << endl; 
    else
        cout << "Error" << endl; 
    return 0; 
} 