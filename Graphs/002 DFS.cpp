class Solution {
public:
    void dfs(int node, vector<bool> &visited, vector<vector<int>> adj, vector<int> &storeDfs ) {
        storeDfs.push_back(node);
        visited[node] = true;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, storeDfs);
            }
        }
    }

    void dfsOfGraph(int V, vector<vector<int>> adj) {
        vector<bool> visited(V + 1, false);
        vector<int> storeDfs;
        for (int i = 1; i < V + 1; ++i) {
            if (!visited[i]) {
                dfs(i, visited, adj, storeDfs);
            }
        }   
        return storeDfs;
    }
}
