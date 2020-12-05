//BEA ROSARI SUPANGA
//2018-10282

//Compile as: g++ EX16.cpp -std=c++17

#include <iostream>     // std::cout
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> project_data;
vector<vector<int>> storage;
//vector<int> project;

void get_items(std::string inputFile, int N) {
    fstream infile(inputFile);
    string data;
        while(getline(infile,data)){
            vector<int> container;
            string y="";
            for(int i=0;i<data.size()-1;i++){
                if(data[i]==' '){
                    container.push_back(stoi(y));
                    y="";
                }
                else{
                    y+=data[i];
                }}
            project_data.push_back(container);
            //project.push_back(0);
        }
}

int main(int argc,char *argv[]){
    if(argc==3){
        int N = atoi(argv[1]);
        int K = atoi(argv[2]);
        get_items("prod_input.txt", N);
        vector<int> W;
        int prod=0;
        int counter=0; 
        for (int x=0; x<N; ++x){
        storage.emplace_back(vector<int>{});
        W.emplace_back(0); }

        while(counter< K){
        int T;
        for(int i=0; i< N; ++i){
            if(i==0){
                T=0;
            }
            else{
                if(project_data[i][W[i]+1]-project_data[i][W[i]] >
                 project_data[T][W[T]+1] - project_data[T][W[T]]){
                    T=i;
                }}}
        ++W[T];
            ++counter;
    }

        cout<<"No. of Workers\n";
        for(int i=0; i<N; ++i){
            prod+=project_data[i][W[i]];  
            cout<< i <<' '<<W[i]<<endl;
            }
            
        /*for(int i=0; i<project.size(); i++){
            cout<<"Project "<< i+1<< ": "<<project[i]<<"\n";
        } */

        cout<<"Total Productivity: "<<prod<<"\n";
    }
}