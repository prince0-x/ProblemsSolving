class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int& nodes, int& edges) {
        vis[node] = true;
        nodes++;
        edges += adj[node].size();
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, nodes, edges);
            }
        }
    }
    int countCompleteComponents(int V, vector<vector<int>>& edg) {
        vector<vector<int>> adj(V);
        for (auto& edge : edg) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(V, false);
        int count = 0;

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                int nodes = 0, edges = 0;
                dfs(i, adj, vis, nodes, edges);
                
                if (edges / 2 == nodes * (nodes - 1) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};