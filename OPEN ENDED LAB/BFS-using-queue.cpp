#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int vertices, edges;
    
      cout << "============================================================="<<endl;
     cout << "                BFS traversal using queue "<<endl;
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

    // Adjacency list (1-based)
    vector<int> adj[21];

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Maximum edges including self-loops = n*(n+1)/2
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

        // Validate vertices
        if (u < 1 || v < 1 || u > vertices || v > vertices)
        {
            cout << "Invalid vertices! Enter values between 1 and " << vertices << endl;
            i--; // retry this edge
            continue;
        }
        // Undirected graph
        adj[u].push_back(v);
        if (u != v) // Avoid double insertion for self-loop
            adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex for BFS (1 to " << vertices << "): ";
    cin >> start;
    // Validate starting vertex
    if (start < 1 || start > vertices)
    {
        cout << "Invalid starting vertex!" << endl;
        return 0;
    }
    // Visited array
    bool visited[21] = {false};
    // Queue for BFS
    queue<int> q;
    // Start BFS
    visited[start] = true;
    q.push(start);
    cout << "\nBFS Traversal: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << "V" << current << " ";
        // Visit all adjacent vertices
        for (int i = 0; i < adj[current].size(); i++)
        {
            int next = adj[current][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    cout << endl;
    return 0;
}
