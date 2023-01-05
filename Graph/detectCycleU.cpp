//Detection of cycle in undirected graph

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph {
    public : 
        int v;

        vector <list <int>> adj;
        vector <bool> visited;

        Graph(int v);

        void addEdge (int v , int w);

        void detectCycle(int s);

        bool dfs(int s , int val);
};

Graph :: Graph(int v) {
    this->v = v;
    adj.resize(v);
    visited.resize(v , false);
}

void Graph :: addEdge (int v , int w) {
    adj[v].push_back(w);
}

void Graph :: detectCycle(int s) {
    for (int i = 0;i < v;i++) {
        if (!visited[i]) {
            if (dfs(i , -1)) {
                cout<<"Cycle is Present"<<endl;
                return;
            }
        }
    }

    cout<<"Cycle is not Present"<<endl;
}

bool Graph :: dfs(int s , int val) {
    visited[s] = true;

    for (int adjacent : adj[s]) {
        if (!visited[adjacent]) {
            if (dfs(adjacent , s)) {
                return true;
            }
        }
        else if (adjacent != val) {
            return true;
        }
    }
    return false;
}

int main () {

    Graph * g = new Graph(6);

    g->addEdge(0 , 1);
    g->addEdge(1 , 0);
    g->addEdge(1 , 2);
    g->addEdge(2 , 1);
    g->addEdge(2 , 3);
    g->addEdge(3 , 2);
    g->addEdge(3 , 1);
    g->addEdge(1 , 3);
    g->addEdge(4 , 5);
    g->addEdge(5 , 4);

    g->detectCycle(0);

    return 0;
}