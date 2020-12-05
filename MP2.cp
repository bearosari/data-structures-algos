//BEA ROSARI B SUPANGA

#include <iostream>         // std::cout
#include <sstream>
#include <ostream>
#include <fstream>          // std::fstream        
#include <iterator>
#include <vector>
#include <cmath>            //for round()
#include <unordered_set>
#include <algorithm>        //for min


using namespace std;
typedef unsigned int uint;

int T;
int N, H;
vector<pair<int,int>> coordinates; //container of coordinates 
int V;
vector<int> pred;
vector<int> connects;

/* A function that computes the distance from one node to another using their x & y coordinates */
double distance(int x, int y, int a, int b){
    if(x==a && y==b){
        return INT_MAX; //return "infinty"
    } 
return sqrt(pow(x - a, 2) + pow(y - b, 2)) + (2*H);
}

/* A function that initializes the graph from the input and convert it to an adjacency matrix */
vector<vector<double>> init(std::ifstream &infile, vector<vector<double>> adjmat){
    
    //infile.ignore(2, '\n'); // skips at most two characters 
    infile >> N >> H;
    int x, y;

    for(uint i = 0; i < N; ++i){
        infile >> x >> y;
        coordinates.emplace_back( std::make_pair(x,y) );
    }
    adjmat.resize(N, vector<double>(N));
    for(uint i =0; i<N; i++){
        for(uint j =0; j<N; j++){
        int v1=coordinates[i].first;
        int v2=coordinates[i].second;
        int u1=coordinates[j].first;
        int u2=coordinates[j].second;
        adjmat[i][j]=distance(v1,v2,u1,u2);
        //cout << adjmat[i][j] << " ";
        }
    }
    return adjmat;
}


/* A function that finds the set of vertex i */
int find(int i) { 
    while (pred[i] != i) 
        i = pred[i]; 
    return i; 
} 
  

/* A function that connects i and j and returns false if both are already in the same set*/
void connect_nodes(int i, int j) { 
    int u = find(i); 
    int v = find(j); 
    pred[u] = v; 
} 
  
/* The main function for the MST Kruskals Algorithm */
void MST(vector< vector<double>> cost, ostream &fout) { 
    double tot_min_weight = 0; // initializing the total minimum weight of the path 
  
    // Initializing the set of disjoint sets
    for (int i = 0; i < V; i++){
        pred[i] = i; 
        connects[i] = 0;
    }
  
    // Include minimum weight edges one by one 
    int counter_edge = 0; 
    while (counter_edge < V - 1) { 
        double min = INT_MAX;
        int u = -1, v = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                //Condition to connect
                //Limit to 2 nodes only
                if (find(i) != find(j) && cost[i][j] < min && connects[i] < 2 && connects[j] <2) { 
                    min = cost[i][j]; 
                    u = i; 
                    v = j; 
                } 
            } 
        } 
  
        connect_nodes(u, v); 
        connects[u] += 1;  //Counts how many nodes connected to node u; 
        connects[v] += 1;  //Counts how many nodes connected to node V; 


        counter_edge++;
        tot_min_weight += min; 
    } 
    //cout << round(tot_min_weight) << endl;
    fout << round(tot_min_weight) << endl;
} 

/* A function that prints the interchangeable start and end node of the path */
void print_ends(ostream &fout){
    for(int i=0; i< connects.size(); i++){
        //If the node is only connected once to another node, it is one of the 2 ends of the path
        if(connects[i]==1)
            //Outputs the x and y coordinate of the node stored in the coordinate vector accessed through the index 
            fout << coordinates[i].first << " " << coordinates[i].second<< " ";
    }
    fout << endl;
}

int main(){
    std::ifstream infile("input.txt", std::ios::in);
    infile >> T;

    for(uint i = 0; i < T; ++i){
        vector< vector<double> > adjmat;
        adjmat= init(infile, adjmat);
        V=N;
        pred.resize(N);
        connects.resize(N);
        vector<vector<int>> state(adjmat.size());
        std::ofstream fout("output.txt", ios::app);
        //Note: I used the append feature so for the next compilation run, same answer will be appended to the same file. 
        MST(adjmat,fout); 
        print_ends(fout);
        coordinates.clear();
    } 
}