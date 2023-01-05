//Detection of cycle in directed graph

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph {
    public :
        int v;
    
        vector <list<int>> adj;
        vector <bool> visited;
        vector <bool> recstack;
    
        Graph(int v);
    
        void addEdge (int v , int w);
    
        void detectCycle (int s);
    
        bool dfs(int s);
};

Graph :: Graph (int v) {
    this->v = v;
    adj.resize(v);
    visited.resize(v , false);
    recstack.resize(v , false);
}

void Graph :: addEdge (int v , int w) {
    adj[v].push_back(w);
}

void Graph :: detectCycle (int s) {
    for (int i = 0;i < v;i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout<<"Cycle is Present"<<endl;
                return;
            }
        }
    }

    cout<<"Cycle is not Present"<<endl;
}

bool Graph :: dfs (int s) {
    visited[s] = true;
    recstack[s] = true;

    for (int adjacent : adj[s]) {
        if (!visited[adjacent]) {
            if (dfs(adjacent)) {
                return true;
            }
        }
        else if (recstack[adjacent]) {
            return true;
        }
    }

    recstack[s] = false;
    return false;
}

int main () {

    Graph * g = new Graph(6);

    g->addEdge(0 , 1);
    g->addEdge(1 , 4);
    g->addEdge(4 , 3);
    g->addEdge(3 , 0);
    g->addEdge(2 , 5);

    g->detectCycle(0);

    return 0;
}