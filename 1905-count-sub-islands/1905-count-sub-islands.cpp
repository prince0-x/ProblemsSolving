class Solution {
public: 
bool bfs(int i, int j,int n, int m,vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis ){
    vis[i][j]=1;
    bool ans = true;
    queue<pair<int, int>>q;
    q.push({i, j});

    vector<int>d={0, 1, 0, -1, 0};
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=1;i<5;i++){
            int nx = x+d[i-1];
            int ny = y+d[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m &&!vis[nx][ny] && grid2[nx][ny]==1)
            {
                if(grid1[nx][ny]==0){
                    ans=false;
                }
                vis[nx][ny]=1;
                q.push({nx, ny});
            }
        }

    }
    return ans;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0, n= grid2.size(), m = grid2[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j] && grid1[i][j]){
                   if( bfs(i, j,n, m, grid1, grid2, vis)){
                    ans++;
                   }
                }
            }
        }
        return ans;
    }
};