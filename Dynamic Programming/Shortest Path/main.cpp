#include <iostream>
#include <vector>
using namespace std; 


// Example graph represented as an adjacency matrix
vector<vector<int>> graph = {
    {0, 2, 4, 0, 0},
    {0, 0, 1, 7, 0},
    {0, 0, 0, 0, 3},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};

int source = 0;
int destination = 4;






int main() {
    

    // Initialize memoization table with -1
    vector<vector<int>> memo(graph.size(), vector<int>(graph.size(), -1));

    int shortestPath = dijkstra(graph, source, destination, memo);

    if (shortestPath == INF) {
        cout << "No path found." << endl;
    } else {
        cout << "Shortest path from " << source << " to " << destination << ": " << shortestPath << endl;
    }

    return 0;
}