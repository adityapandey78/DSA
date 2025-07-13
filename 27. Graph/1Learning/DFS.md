```cpp
class Solution {
    private:
    void dfs(int node,vector<vector<int>>&adj, vector<int>&vis, vector<int>&ls){
        vis[node]=1;
        ls.push_back(node);
        // traverse to all its neighbours
        for(auto it:adj[node]){//recursively DFS wali call lgte rahe
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int>vis(n,0);
        int start=0;
        vector<int>ls;
        dfs(start,adj,vis,ls);
        return ls;
        
    }
};
```