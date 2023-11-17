/*
Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and verify the time complexity.
*/

#include <iostream>
#include <climits>
using namespace std;
struct DirectedEdge {
    int source, destination, weight;
};
void BellmanFord(DirectedEdge edges[], int V, int E, int source) {
    int dist[V];
    fill(dist, dist + V, INT_MAX);
    dist[source] = 0;
   for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source, v = edges[j].destination, w = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i].source, v = edges[i].destination, w = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }
    cout << "Vertex:\t\tDistance from Source:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "   " << i << "\t\t\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
    }
}
int main() {
    int V = 7, E = 10;
    DirectedEdge edges[] =
    {{0, 1, 6}, 
    {0, 2, 5}, 
    {0, 3, 5}, 
    {2, 1, -2}, 
    {3, 2, -2},
    {3, 4, -1}, 
    {1, 5, -1},
    {2, 5, -1},
    {4, 6, 3}, 
    {5, 6, 3}};
    int start;
    cout << "Enter the starting source: ";
    cin >> start;
    BellmanFord(edges, V, E, start);
    return 0;
}
