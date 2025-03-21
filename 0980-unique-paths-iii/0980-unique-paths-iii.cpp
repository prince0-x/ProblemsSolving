class Solution {
public:
    vector<pair<int, int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

    int solve(int row, int col,int left, vector<vector<bool>>&vis,vector<vector<int>>&grid, int m, int n){
        // base case
        // cout<<row<<" "<<col<<"\n";
        if(grid [row][col] == 2)
        {
            // cout<<"\n";
            if(left == 0)  return 1;
            else return 0;
        }
        vis[row][col] = true;
        int ans = 0;
        for(auto [x, y]: directions)
        {
            int newx = row + x;
            int newy = col + y;

            if((newx<m and newy<n and newx>=0 and newy >= 0) && !vis[newx][newy] && grid[newx][newy]!=-1 )
            {
                ans += solve(newx, newy, left-1, vis, grid, m, n);
            }
        }
        vis[row][col] = false;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = 0, startx , starty;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++)
            {
                if(grid[i][j]==1){
                    startx = i;
                    starty = j;
                }
                if(grid[i][j]==0){
                    left++;
                }
            }
        }
        return solve(startx, starty, left+1, vis, grid, m, n);
    }
};