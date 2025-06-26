class Solution {
public:
    vector<pair<int, int>>directions ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<bool>>vis(R, vector<bool>(C, false));
        int ans =0;
        
        for(int i =0;i<R;i++){
           for(int j =0; j<C;j++){
               if((i==0 || j==0 || i==R-1 || j== C-1) && grid[i][j]==1)
               {
                    q.push({i, j});
                    vis[i][j]=1;
               }
           }
        }
        auto issafe = [&](int a, int b){
            return a>=0 && a<R && b>=0 && b<C;
        };
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir: directions){
                int newx = x+dir.first;
                int newy = y+dir.second;
                if(issafe(newx, newy) && !vis[newx][newy] && grid[newx][newy]==1){
                    vis[newx][newy]=1;
                    q.push({newx, newy});
                }
            }
        }
        for(int i =0;i<R;i++){
           for(int j =0; j<C;j++){
               if( grid[i][j]==1 && !vis[i][j])
               {
                    ans++;
               }
           }
        }
        return ans;
    }
};