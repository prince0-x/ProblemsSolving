class Solution {
public:
vector<vector<int>>dp;
int solve( int i,int j,int n, int m, vector<vector<int>>& mat){
    if(!(i>=0 && i<=n && j>=0 && j<m))return 0;
    if(dp[i][j]!= -1) return dp[i][j];

    int ans = 1;
    if(j+1 < m && mat[i][j+1] > mat[i][j]){
        ans = max(ans, 1+solve( i,j+1,n, m ,mat));
    }
    if(j-1>=0 && mat[i][j-1] > mat[i][j]){
        ans= max(ans, 1+solve( i, j-1,n, m, mat));
    }
    if(i+1 < n && mat[i+1][j] > mat[i][j]){
        ans = max(ans, 1+solve( i+1,j,n, m, mat));
    }
    if(i-1>=0 && mat[i-1][j] > mat[i][j]){
        ans= max(ans, 1+solve( i-1, j, n, m, mat));
    }

    return dp[i][j] = ans;
    
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0 ;
        dp.resize(n, vector<int>(m, -1));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                res = max(res, solve(i, j, n, m, matrix));
            }
        }
        return res;
    }
};