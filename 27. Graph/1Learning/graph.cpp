#include<iostream>
#include<vector>
using namespace std;
//adjacency matrix
int main(){
    int n, m;
    
    cout << "Enter the number of nodes (N) and edges (M):\n";
    cin >> n >> m;

    
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    
    cout << "Enter the " << m << " edges (format: u v):\n";
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "\nAdjacency Matrix of the graph:\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}