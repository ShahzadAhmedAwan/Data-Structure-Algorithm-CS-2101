#include <iostream>
#include <vector>
using namespace std;

// -------------------------------
// DFS Function using Recursion
// -------------------------------
// This function performs Depth-First Search starting from 'vertex'.
// It recursively visits all unvisited vertices connected to the current vertex.
void DFS(int vertex, vector<int> adj[], bool visited[])
{
    // Mark current vertex as visited
    visited[vertex] = true;

    // Print the vertex (part of DFS traversal output)
    cout << "V" << vertex << " ";

    // Explore all adjacent vertices
    for (int i = 0; i < adj[vertex].size(); i++)
    {
        int next = adj[vertex][i];

        // If the adjacent vertex has not been visited, recursively call DFS
        if (!visited[next])
        {
            DFS(next, adj, visited); // <-- Recursive call happens here
        }
    }
}
int main()
{
    int vertices, edges;
     cout << "============================================================="<<endl;
     cout << "                DFS traversal using Recursion "<<endl;
     cout << "============================================================="<<endl;
    // Input the number of vertices in the graph
    cout << "Enter number of vertices (1 to 20): ";
    cin >> vertices;
    // Validate vertices
    if (vertices <= 0 || vertices > 20)
    {
        cout << "Invalid number of vertices!" << endl;
        return 0;
    }
    // Create adjacency list for the graph (1-based indexing)
    vector<int> adj[21]; // adj[1] to adj[vertices]
    // Input the number of edges
    cout << "Enter number of edges: ";
    cin >> edges;
    // Input edges from the user
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (vertex1 vertex2): ";
        cin >> u >> v;

        // Validate vertex numbers
        if (u < 1 || v < 1 || u > vertices || v > vertices)
        {
            cout << "Invalid vertices! Enter values between 1 and " << vertices << endl;
            i--; // Retry this edge
            continue;
        }

        // Add edge to adjacency list (undirected graph)
        adj[u].push_back(v);
        if (u != v) // Avoid duplicate entry for self-loop
            adj[v].push_back(u);
    }
    // Input starting vertex for DFS traversal
    int start;
    cout << "Enter starting vertex for DFS (1 to " << vertices << "): ";
    cin >> start;
    // Validate starting vertex
    if (start < 1 || start > vertices)
    {
        cout << "Invalid starting vertex!" << endl;
        return 0;
    }

    // Visited array to keep track of visited vertices during DFS
    bool visited[21] = {false};

    cout << "\nDFS Traversal: ";

    // Call DFS starting from 'start' vertex
    DFS(start, adj, visited); // <-- This starts the recursive DFS

    cout << endl;

    return 0;
}
