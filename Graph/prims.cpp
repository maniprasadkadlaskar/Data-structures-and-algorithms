#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<limits.h>

using namespace std;

class Graph {
    public : 
        int v , e;

        vector<list<pair<int , int>>> adj;

        Graph(int v , int e);

        void addEdge (int a , int b , int w);

        void primsAlgorithm ();
        
};

Graph :: Graph(int v , int e) {
    this->v = v;
    this->e = e;
    adj.resize(v);
}

void Graph :: addEdge (int a , int b , int w) {
    adj[a].push_back({b , w});
}

void Graph :: primsAlgorithm () {
    int parent[v];
    int key[v];
    bool mst[v];

    for (int i = 0;i < v;i++) {
        key[i] = INT_MAX;
        mst[i] = false;
    }

    priority_queue <pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0 , 0});

    for (int i = 0;i < v - 1;i++) {
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto k : adj[u]) {
            int node = k.first;
            int weight = k.second;

            if (mst[node] == false and weight < key[node]) {
                parent[node] = u;
                pq.push({weight , node}); //check here
                key[node] = weight;
            }
        }
    }

    for (int i = 0;i < v;i++) {
        cout<<parent[i]<<" - "<<i<<endl;
    }

    int cost = 0;

    for (int i = 0;i < v;i++) {
        cost += key[i];
    }

    cout<<"Total cost : "<<cost<<endl;
}


int main () {

    Graph * g = new Graph(5 , 6);

    g->addEdge(0 , 3 , 3);
    g->addEdge(0 , 4 , 5);
    g->addEdge(4 , 2 , 3);
    g->addEdge(4 , 0 , 5);
    g->addEdge(3 , 0 , 3);
    g->addEdge(3 , 1 , 2);
    g->addEdge(3 , 2 , 4);
    g->addEdge(1 , 3 , 2);
    g->addEdge(1 , 2 , 1);
    g->addEdge(2 , 3 , 4);
    g->addEdge(2 , 1 , 1);
    g->addEdge(2 , 4 , 3);
    
    
    g->primsAlgorithm();

    return 0;
}