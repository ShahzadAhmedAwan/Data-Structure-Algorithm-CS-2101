#include <iostream>
using namespace std;

int main()
{
    int vertices, edges;
     cout << "============================================================="<<endl;
     cout << "             Graph Representation using adjancy Matix"<<endl;
     cout << "============================================================="<<endl;
    // Input number of vertices
    cout << "Enter number of vertices (1 to 20): ";
    cin >> vertices;
    if (vertices <= 0 || vertices > 20)
    {
        cout << "Invalid number of vertices!" << endl;
        return 0;
    }
    // Initialize adjacency matrix
    int graph[21][21] = {0}; // Using 1-based indexing
    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;
    // Maximum edges in undirected graph with self-loops = n*(n+1)/2
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
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix Representation:\n\n   ";
    for (int i = 1; i <= vertices; i++)
        cout << "V" << i << " ";
    cout << endl;

    for (int i = 1; i <= vertices; i++)
    {
        cout << "V" << i << " ";
        for (int j = 1; j <= vertices; j++)
        {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
