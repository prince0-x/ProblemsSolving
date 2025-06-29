class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto issafe = [&](int a, int b){
            return a>=0 && a<n && b>=0 && b<m;
        };
        vector<pair<int, int>>direct = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>>vis(n, vector<int>(m, 0)), dist(n, vector<int>(m, 0));;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    pq.push({0, i, j});
                    vis[i][j]=1;
                }
            }
        }
        while(!pq.empty()){
            auto [d, x, y] = pq.top();
            pq.pop();

            for(auto dir:direct){
                int nx = x+dir.first;
                int ny = y+dir.second;
                if(issafe(nx,ny) && !vis[nx][ny] && mat[nx][ny]==1){
                    dist[nx][ny]=1+d;
                    vis[nx][ny]=1;
                    pq.push({1+d, nx, ny});
                }
            }
        }
        return dist;
    }
};