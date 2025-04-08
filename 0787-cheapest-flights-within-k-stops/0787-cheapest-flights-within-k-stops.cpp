class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        queue<tuple<int, int, int>> q;
        q.push({src, 0, 0});

        vector<int> minCost(n, INT_MAX);
        
        minCost[src] = 0;

        while (!q.empty()) {
            auto [node, stops, cost] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto [nbr, wt] : adj[node]) {
                if (cost + wt < minCost[nbr]) {
                    minCost[nbr] = cost + wt;
                    q.push({nbr, stops + 1, cost + wt});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};