class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        queue<pair<int, pair<int, int>>>q;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0, {src, 0}}); // {step, node, weight}
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second.first;
            int dis  = q.front().second.second;
            q.pop();
            if(step >k)break;
            for(auto [nbr, wtnbr]:adj[node]){
                if(dis + wtnbr < dist[nbr]){
                    dist[nbr]=dis+wtnbr;
                    q.push({step+1, {nbr, wtnbr+dis}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};