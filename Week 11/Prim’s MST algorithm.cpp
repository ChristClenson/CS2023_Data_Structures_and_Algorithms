#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int destination;
    int weight;
};

void addEdge(vector<vector<Edge>>& graph, int src, int dest, int weight) {
    Edge edge1 = {dest, weight};
    Edge edge2 = {src, weight};
    graph[src].push_back(edge1);
    graph[dest].push_back(edge2);
}

void primMST(vector<vector<Edge>>& graph, int vertices) {
    vector<int> key(vertices, INT_MAX);
    vector<bool> mstSet(vertices, false);
    vector<int> parent(vertices, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int startVertex = 0;
    key[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<Edge>> graph(vertices);

    for (int i = 0; i < edges; ++i) {
        int src, dest, weight;
        cout << "Enter the source, destination, and weight of edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    primMST(graph, vertices);

    return 0;
}
