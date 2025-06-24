class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        using ll = long long;

        
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto& arr : roads) {
            adj[arr[0]].push_back({arr[2], arr[1]});
            adj[arr[1]].push_back({arr[2], arr[0]});
        }

        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<ll> dist(n, LLONG_MAX);
        vector<int> path(n, 0);

        dist[0] = 0;
        path[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;  

            for (auto [nbrCost, nbr] : adj[node]) {
                ll newDist = cost + nbrCost;

                if (newDist < dist[nbr]) {
                    dist[nbr] = newDist;
                    path[nbr] = path[node];
                    pq.push({newDist, nbr});
                }
                else if (newDist == dist[nbr]) {
                    path[nbr] = (path[nbr] + path[node]) % mod;
                }
            }
        }

        return path[n - 1];
    }
};
