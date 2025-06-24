class Solution {
public:
    vector<vector<int>>dp;
    const int mod = 1e9+7;
    int n,m;
    bool valid(int a, int b){
        return a>=0 && b>=0 && a<n && b<m;
    }
    int rec(int r, int c, vector<vector<int>>& mat){
        long long res = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        if(dp[r][c]!=-1)return dp[r][c];
        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(!valid(nr,nc))continue;
            if(mat[nr][nc] > mat[r][c]){
                res= (0LL+res+rec(nr, nc, mat))%mod;
            }
        }
        return dp[r][c]=res%mod;
    }
    int countPaths(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        dp.resize(n, vector<int>(m, -1));
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                ans= (0LL+ans+rec(i, j, mat))%mod;
            }
        }
        return ans;
    }
};