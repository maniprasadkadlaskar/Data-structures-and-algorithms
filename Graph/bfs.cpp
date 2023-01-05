#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph {
    public :
        int v;

        vector <list<int>> adj;
        vector <bool> visited;

        Graph(int v);

        void addEdge (int v , int w);

        void bfsTraversal (int s);

        void bfs(int s);
};

Graph :: Graph (int v) {
    this->v = v;
    adj.resize(v);
    visited.resize(v , false);
}

void Graph :: addEdge (int v , int w) {
    adj[v].push_back(w);
}

void Graph :: bfsTraversal (int s) {
    for (int i = 0;i < v;i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }
}

void Graph :: bfs(int s) {

    list <int> queue;
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty()) {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for (int adjacent : adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main() {

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

    g->bfsTraversal(0);

    return 0;
}