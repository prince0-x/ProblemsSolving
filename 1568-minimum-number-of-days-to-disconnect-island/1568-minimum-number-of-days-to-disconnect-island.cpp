class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        function<bool(int,int)> issafe = [&](int a, int b) {
            return a >= 0 && b >= 0 && a < n && b < m;
        };

        function<int()>count_island=[&](){
            vector<vector<int>>vis(n, vector<int>(m, 0));
            int num_islands=0;
            function<void(int, int)>bfs = [&](int i, int j){
                queue<pair<int, int>>q;
                q.push({i, j});
                vis[i][j]= 1;
                while(!q.empty()){
                    auto [x, y]=q.front();
                    q.pop();
                    for(auto dir: direct){
                        int nx=x+dir[0], ny= y+dir[1];
                        if(issafe(nx, ny) && !vis[nx][ny] && grid[nx][ny]==1){
                            vis[nx][ny]=1;
                            q.push({nx, ny});
                        }
                    }
                }
            };
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && grid[i][j]==1){
                        bfs(i, j);
                        num_islands++;
                    }
                }
            }
            return num_islands;
        };
        if(count_island() != 1) return 0;

       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(count_island() != 1) return 1;
                    grid[i][j]=1;
                }
            }
        }
        
        return 2;
    }
};