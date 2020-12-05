//TOPOLOGICAL SORT
//2018-11041
#include <fstream>
#include <stack>
#include <algorithm>
#include <iostream>         // std::cout
#include <vector>           // std::vector for array container
#include <queue>            // BFS
#include <unordered_map>    // node int key to string label hash table
using namespace std;


typedef unsigned int uint;

// A class containing an implementation of a graph using 
//      adjacency list representation with methods for standard traversal
class Graph {
private:
    std::vector<std::vector<int>> adjList;
    std::unordered_map<int,std::string> nodeLabels;
    std::vector<bool> visitedNodes;
    vector<string> labels;
    void init_manual_helper(int node, std::vector<int> nodeList);
public:
    Graph() {};
    void clearVisited();
    void tplgclsrt(int node, stack<int>& s);
    void topologicalsort();
    void init(std::string inputFile);
};


void Graph::clearVisited() {
    for(uint i = 0; i < this->visitedNodes.size(); ++i) {
        visitedNodes[i] = false;
    }
}


void Graph::tplgclsrt(int node, stack<int>& s) { 

    this -> visitedNodes[node] = true; 
  
    for (uint i=0; i< this-> adjList[node].size(); ++i){
        if(!visitedNodes[this->adjList[node][i]]){
            tplgclsrt(this-> adjList[node][i],s);
        }
    }
    s.push(node); 
} 

void Graph::topologicalsort() {
    stack<int> s;


    for(uint node = 0; node < this->adjList.size(); ++node) {
        if(!visitedNodes[node]) {
            tplgclsrt(node, s);
        }
    }


    while (!s.empty()){
        int n=s.top();
       // cout << n << " ";
        cout << labels[n] << ' '; 
        s.pop();
    }
} 


void Graph::init(std::string inputFile) {
    // Read exercise12c.in

    ifstream inFile(inputFile);
    string line;
    getline(inFile, line);
    uint V, E;
    V= stoi(line.substr(0,line.find(" ")));
    E= stoi(line.substr(line.find(" ")+1,line.size()));

    uint numNodes = V;
    for(uint i = 0; i < numNodes; ++i) {
        this->adjList.emplace_back(std::vector<int>{});
        this->visitedNodes.emplace_back(false);
    }

    for(uint i = 0; i < this->adjList.size(); ++i) {
        getline(inFile, line);
       // cout << line << endl;
        this ->labels.push_back(line);
       // this->nodeLabels[i] = line;
    }

    for(uint i = 0; i < E; ++i) {
        getline(inFile, line);
        this->adjList[stoi(line.substr(0,line.find(" ")))].emplace_back(stoi(line.substr(line.find(" ")+1,line.size())));
    }

    inFile.clear();
}

int main() {
    Graph g;

    g.init("exercise13.in");

    g.clearVisited();
    g.topologicalsort();
    std::cout << '\n';
}