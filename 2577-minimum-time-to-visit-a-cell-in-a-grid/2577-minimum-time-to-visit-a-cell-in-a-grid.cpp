class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][1] >1 && grid[1][0]>1)return -1;
        vector<vector<int>>directions = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        auto issafe = [&](int a, int b){
            return a<n && a>=0 && b<m && b>=0;
        };

        vector<vector<int>>vis(n , vector<int>(m, 0));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;

        pq.push({0,0,0});
        vis[0][0]=1;

        while(!pq.empty()){
            auto [cur_time, x, y] = pq.top();
            if(x == n-1 && y == m-1) return cur_time;
            pq.pop();
            for(auto dir:directions){ 
                int nx = x + dir[0];
                int ny = y + dir[1];
                if(issafe(nx, ny) && !vis[nx][ny] && cur_time+1 >=grid[nx][ny]){
                    vis[nx][ny]=1;
                    pq.push({cur_time+1, nx, ny});                   
                }
                else if(issafe(nx, ny) && !vis[nx][ny] && cur_time+1 < grid[nx][ny]){
                    int diff = grid[nx][ny]- cur_time;
                    vis[nx][ny]=1;
                    if(diff%2){
                        pq.push({grid[nx][ny], nx, ny});    
                    }else{
                        pq.push({grid[nx][ny]+1, nx, ny}); 
                    }
                    
                }
            }
        }
        return -1;
    }
};