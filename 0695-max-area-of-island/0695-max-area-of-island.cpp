class Solution {
public:
    vector<vector<int>>dir={{0, 1}, {1, 0}, {0, -1}, {-1,0}};
    inline bool issafe(int a, int b, int n, int m){
        return a>=0 && b>=0 && a<n && b<m;
    }
    int dfs(int r, int c, int n, int m, vector<vector<int>>&grid, vector<vector<int>>&vis){
        vis[r][c]=1;
        int ans = 1;
        for(auto dr:dir){
            int nr = r+dr[0];
            int nc = c+dr[1];
            if(issafe(nr, nc, n, m) && !vis[nr][nc] && grid[nr][nc]){
                ans+=dfs(nr, nc, n, m, grid, vis);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]){
                    int val = dfs(i, j, n, m, grid, vis);
                    ans= max(ans, val);
                }
            }
        }
        return ans;
    }
};