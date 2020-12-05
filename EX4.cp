#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector <string> wordlist;
    while(1){
    string userInput;
    cout << "Enter a command: ";
    //breaks "add word" into "add" and "word"
    getline(cin, userInput);

    string cmd;
    string arg;
    stringstream ss(userInput);

    ss >> cmd;
    ss >> arg;
    

    //cout << cmd << endl;
    if (cmd=="add"){
        if(arg.empty()){
        cout << "No word to add." << endl;
        }  
        else {
        wordlist.push_back(arg);
        //cout << "ADDED" <<endl;
        //cout << arg << endl;
        }

    }

    else if (cmd=="print"){
        if(!arg.empty()){
        cout << "Invalid command." << endl;
        }  
        else {
        if(!wordlist.empty())
        {
        vector<string>::iterator iter = wordlist.begin();
            while(true)
            {
            cout << *iter;
            ++iter;
                if(iter == wordlist.end())
                {
                cout << "\n";
                break;
                }
                 else
                {   
                cout << ", ";
        }
        }   
        }  else {
            cout << "No word(s) to print." << endl;
        }
        } 
        
}
        else if (cmd=="delete"){
        if(!wordlist.empty())
        {
        vector<string>::iterator itr = find(wordlist.begin(), wordlist.end(), arg);
        if (itr == wordlist.end()){
        cout << arg << " not found." << endl;
        }
        else{
        wordlist.erase(itr);
        }
        }
        else {
            cout << "Not word to delete." << endl;
        }

        }


        else if (cmd=="stop"){
        if(!arg.empty()){
        cout << "Invalid command." << endl;
        }  
        else {
            break;
        }
        }

        else{
        cout << "Invalid keyword." << endl;

        }

}
}



