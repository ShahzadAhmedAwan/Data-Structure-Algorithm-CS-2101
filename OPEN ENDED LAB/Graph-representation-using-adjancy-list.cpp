#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int vertices, edges;
     cout << "============================================================="<<endl;
     cout << "              Graph Representation using Adjancey list  "<<endl;
     cout << "============================================================="<<endl;
    // Input number of vertices
    cout << "Enter number of vertices (1 to 20): ";
    cin >> vertices;

    // Validate vertices
    if (vertices <= 0 || vertices > 20)
    {
        cout << "Invalid number of vertices!" << endl;
        return 0;
    }

    // Create adjacency list (1-based)
    vector<int> adj[21]; // Using index 1 to vertices

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Maximum edges in undirected graph including self-loops = n*(n+1)/2
    if (edges < 0 || edges > vertices * (vertices + 1) / 2)
    {
        cout << "Invalid number of edges!" << endl;
        return 0;
    }

    // Input edges
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter edge " << i + 1 << " (vertex1 vertex2): ";
        cin >> u >> v;

        // Validate vertex numbers
        if (u < 1 || v < 1 || u > vertices || v > vertices)
        {
            cout << "Invalid vertices! Enter values between 1 and " << vertices << endl;
            i--; // retry this edge
            continue;
        }

        // Undirected graph
        adj[u].push_back(v);
        if (u != v) // Avoid double entry for self-loop
            adj[v].push_back(u);
    }

    // Display adjacency list
    cout << "\nAdjacency List Representation:\n";
    for (int i = 1; i <= vertices; i++)
    {
        cout << "V" << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << "V" << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
