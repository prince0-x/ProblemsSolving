class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[201][201];
        memset(dp, -1, sizeof dp);
        function<int(int, int)>solve=[&](int l, int r){
            if(l>=r)return 0;
            if (dp[l][r] != -1){
                return dp[l][r];
            }
            int ans= INT_MAX;
            for(int k=l; k<=r; k++){
                ans=min(ans, k+max(solve(l, k-1), solve(k+1, r)));
            }
            return dp[l][r]=ans;
        };
        return solve(1, n);
    }
};