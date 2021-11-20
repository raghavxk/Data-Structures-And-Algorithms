class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<vector<int>> adj) {
        vector<int> bfs;
        vector<bool> visited(V + 1, false);
        for (int i = 1; i < V + 1; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for (auto it : adj[node]) {
                        if (!visited[it]) {
                            q.push_back(it);
                            visited[it] = true;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};

