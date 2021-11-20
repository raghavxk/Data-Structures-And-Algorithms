class Solution {
public:

    void checkForCycle(int s, int V, vector<vector<int>> adj, vector<int> &visited) {

        queue<int, int> q;
        visited[s] = true;
        q.push({s, -1});

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second();
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }


    bool isCycle(int V, vector<vector<int>> adj) {
        vector<bool> visited(V + 1, false);
        for (int i = 1; i < V + 1; ++i) {
            if (!visited[i]) {
                if (checkForCycle(i, V, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
