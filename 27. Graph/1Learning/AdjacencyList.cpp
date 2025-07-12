#include<iostream>
#include<vector>
#include<utility> // For std::pair

using namespace std;

int main(){
    
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Adjacency list for a weighted graph
    // adj[i] will store a list of pairs {neighbor, weight}
    vector<vector<pair<int, int>>> adj(n + 1);
    
    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // For an undirected graph, add the reverse edge as well
        adj[v].push_back({u, w}); 
    }

    // Print the adjacency list
    cout << "\nAdjacency List (Node -> {Neighbor, Weight}):" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (const auto& edge : adj[i])
        {
            cout << "{" << edge.first << ", " << edge.second << "} ";
        }
        cout << endl;
    }

    return 0;
}

/*
Example Input:
Enter the number of nodes and edges: 5 6
Enter the edges (u, v, weight):
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
4 5 9

Expected Output:
Adjacency List (Node -> {Neighbor, Weight}):
1 -> {2, 2} {3, 6} 
2 -> {1, 2} {3, 7} {4, 4} {5, 2} 
3 -> {1, 6} {2, 7} 
4 -> {2, 4} {5, 9} 
5 -> {2, 2} {4, 9} 
*/