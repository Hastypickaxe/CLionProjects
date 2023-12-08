#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 1e9; // A large constant to represent infinity

// Structure to represent a vertex and its distance from the source
struct Node {
    int vertex;
    int distance;

    // Overloading the comparison operator for the priority queue
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Helper function to print all paths
void printAllPaths(int start, int destination, stack<int>& path, vector<int>& distance) {
    queue<int> reversedPath;

    while (!path.empty()) {
        reversedPath.push(path.top());
        path.pop();
    }

//    cout << start;

    while (!reversedPath.empty()) {
        cout << " -> " << reversedPath.front();
        reversedPath.pop();
    }

    cout << " (" << distance[destination] << ")";
}

// Dijkstra's algorithm implementation
void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();

    for (int dest = 0; dest < n; ++dest) {
        // Priority queue to store nodes with their distances
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Vector to store the minimum distances from the source
        vector<int> distance(n, INF);

        // Vector to store predecessors for path reconstruction
        vector<int> predecessor(n, -1);

        // Enqueue the source node with distance 0
        pq.push({start, 0});
        distance[start] = 0;

        // Dijkstra's algorithm
        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            int u = current.vertex;
            int dist = current.distance;

            // Explore neighbors of the current node
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (dist + weight < distance[v]) {
                    distance[v] = dist + weight;
                    predecessor[v] = u;  // Update predecessor for path reconstruction
                    pq.push({v, distance[v]});
                }
            }
        }

        // Print out all possible paths
        stack<int> path;
        int current = dest;
        while (current != -1) {
            path.push(current);
            current = predecessor[current];
        }

        cout << start << " -> " << dest << " : ";
        printAllPaths(start, dest, path, distance);
        cout << endl;
    }
}

int main() {
    // Get input file name and start node from the user
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    int start;
    cout << "Enter start node: ";
    cin >> start;

    // Read graph from the file
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file.\n";
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;

    // Represent the graph as an adjacency list of pairs (neighbor, weight)
    vector<vector<pair<int, int>>> graph(numVertices);

    // Read edges and weights from the file
    for (int i = 0; i < numEdges; ++i) {
        int u, v, weight;
        inputFile >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        graph[v].emplace_back(u, weight);  // Add this line for undirected graph
    }

    // Run Dijkstra's algorithm and print all possible paths
    dijkstra(graph, start);

    return 0;
}
