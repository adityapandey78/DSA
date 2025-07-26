// Disjoint Set Union (DSU) implementation with Union by Rank and Union by Size

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
    
public:
    // Constructor: Initialize DSU for n nodes (0 to n)
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);  // Fixed: Initialize size to 1, not 0
        parent.resize(n+1);

        // Each node is initially its own parent
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    // Find ultimate parent with path compression optimization
    int findUPar(int node){
        if(node == parent[node]) 
            return node;
        // Path compression: make every node point directly to root
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank: attach smaller rank tree under root of higher rank tree
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);  // Ultimate parent of u
        int ulp_v = findUPar(v);  // Ultimate parent of v

        // If both nodes already belong to same component, do nothing
        if(ulp_u == ulp_v) return;
        
        // Attach smaller rank tree under root of higher rank tree
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            // If ranks are equal, make one root and increment its rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size: attach smaller size tree under root of larger size tree
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);  // Ultimate parent of u
        int ulp_v = findUPar(v);  // Ultimate parent of v

        // If both nodes already belong to same component, do nothing
        if(ulp_u == ulp_v) return;
        
        // Always attach smaller size tree to larger size tree
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Fixed: Update size of new root
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];  // Fixed: Update size of new root
        }
    }
};

int main(){
    DisjointSet ds(7);
    
    // Perform union operations using union by size
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    // Check if nodes 3 and 7 belong to same component
    if(ds.findUPar(3) == ds.findUPar(7)){  // Fixed: Changed 4 to 7 for correct test
        cout << "Same component\n";
    }
    else {
        cout << "Different components\n";
    }
    
    // Union components containing 3 and 7
    ds.unionBySize(3, 7);

    // Check again after union operation
    if(ds.findUPar(3) == ds.findUPar(7)){  // Fixed: Changed 4 to 7 for correct test
        cout << "Same component\n";
    }
    else {
        cout << "Different components\n";
    }
    
    return 0;
}