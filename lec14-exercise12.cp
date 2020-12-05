#include "lec14-exercise12.h"
#include <fstream>

// Typical recursive postorder DFS (for connected graph)
void Graph::postorderDFS(int node) {

    // Set current node as visited
    this->visitedNodes[node] = true;

    // For each unvisited neighbor of the current node, apply DFS
    for(uint i = 0; i < this->adjList[node].size(); ++i) {
        if(!visitedNodes[this->adjList[node][i]]) {
            postorderDFS(this->adjList[node][i]);
        }
    }

    std::cout << node << ' ';    // Process node, e.g. print node label

}


// Typical iterative breadth-first search (BFS)
void Graph::BFS(int node) {
    std::queue<int> q;
    int front;
    // Push the starting node onto the queue and mark it as visited
    q.push(node);
    this->visitedNodes[node] = true;

    // While the queue is not empty    
    while(!q.empty()) {
        // Pop the front of the queue
        front = q.front();
        std::cout << front << ' ';    // Process node, e.g. print node label
        q.pop();

        // For each unvisited neighbor of the popped node
        for(uint i = 0; i < this->adjList[front].size(); ++i) {
            int neighborNode = adjList[front][i];
            if(!this->visitedNodes[neighborNode]) {
                // Push node onto queue and mark as visite
                q.push(neighborNode);
                this->visitedNodes[neighborNode] = true;
            }
        }
    }
}

void Graph::init(std::string inputFile) {
    // Read exercise12c.in
    std::fstream infile(inputFile, std::ios::in);

    // V=number_of_nodes E=number_of_directed_edges
    int V, E;
    infile >> V >> E;
    //std::cout << V << ' ' << E << std::endl;


    // label0
    // label1
    // ...
    // labelV-1
    for(uint i = 0; i < V; ++i) {
        this->adjList.emplace_back(std::vector<int>{});
        this->visitedNodes.emplace_back(false);
    }

    // proceed to the second line
    infile.ignore(2, '\n'); // skips at most two characters (\r\n for windows) or after the next \n

    // edge0
    // edge1
    // ...
    // edgeE-1
    int u, v;
    for(uint i = 0; i < E; ++i) {
        infile >> u >> v;
        //std::cout << u << ' ' << v << std::endl;
        this->adjList[u].emplace_back(v);
    }
}



int main() {
    Graph g;
    //g.init_manual();    // Comment out when using g.init() instead

    // Define the init method to read the graph from file instead of manually generating it through the code
    g.init("exercise12.in");

    std::cout << "Preorder DFS from A: \n\t";
    g.clearVisited();
    g.preorderDFS(0);
    std::cout << '\n';

    std::cout << "Postorder DFS from A: \n\t";
    g.clearVisited();
    g.postorderDFS(0);
    std::cout << '\n';

    std::cout << "BFS from A: \n\t";
    g.clearVisited();
    g.BFS(0);
    std::cout << '\n';
}