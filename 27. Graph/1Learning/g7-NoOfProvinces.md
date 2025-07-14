## No of provinces- Leetcode 547

This problem is about finding the number of connected components (provinces) in an undirected graph.

```cpp
class Solution {
private:
    // DFS function to traverse all connected cities in a province
    void dfs(int node, vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1; // Mark current city as visited
        
        // Visit all adjacent cities (connected cities)
        for(auto it:adj[node]){
            if(!vis[it]){ // If city not visited yet
                dfs(it,adj,vis); // Recursively visit connected cities
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ```cpp
        int n=isConnected.size(); // Number of cities
                
                // Convert adjacency matrix to adjacency list
                vector<vector<int>>adj(n);
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        // If cities i and j are connected and not the same city
                        if(isConnected[i][j]==1 && i!=j){
                            adj[i].push_back(j); // Add bidirectional connection
                            adj[j].push_back(i);
                        }
                    }
                }

                vector<int>vis(n,0); // Visited array to track processed cities
                int cnt=0; // Counter for number of provinces (connected components)
                
                // Iterate through all cities
                for(int i=0;i<n;i++){
                    if(!vis[i]){ // If city not visited (start of new province)
                        cnt++; // Increment province count
                        dfs(i,adj,vis); // Visit all cities in this province
                    }
                }
                return cnt; // Return total number of provinces
        

        
    }
};
```
**Matrix Storage Analogy:**
Think of the adjacency matrix like a friendship table in a school:
```
             City0  City1  City2
        City0  1      1      0     <- City0 is connected to City1
        City1  1      1      1     <- City1 connects to City0 & City2  
        City2  0      1      1     <- City2 is connected to City1
```

**Conversion Process:**
- **Row i, Column j = 1**: Direct road between City i and City j
- **Diagonal (i==j)**: Always 1 (city connects to itself) - we skip this
- **Two nested loops**: Check every possible city pair (i,j) in the matrix
- **Result**: adj[0]={1}, adj[1]={0,2}, adj[2]={1} (adjacency list format)

This creates **2 provinces**: {City0, City1} and {City2} connected through City1.

**Key Concepts:**
- **Connected Components**: Each province is a connected component in the graph
- **DFS Traversal**: Used to explore all cities within a single province
- **Graph Representation**: Converts adjacency matrix to adjacency list for easier traversal
- **Time Complexity**: O(N²) for matrix conversion + O(N+E) for DFS = O(N²)
- **Space Complexity**: O(N) for adjacency list and visited array