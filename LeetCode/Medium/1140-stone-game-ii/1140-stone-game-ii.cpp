class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n==0)return 0;
        vector<int>suff(piles.begin(), piles.end());
        for(int i=n-2; i>=0;i--){
            suff[i]+=suff[i+1];
        }
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        function<int(int, int)> solve=[&](int i, int M){
            if(i==n)return 0;
            if(2*M >= n-i){
                dp[i][M]=suff[i];
                return suff[i];
                }
            if(dp[i][M] != -1){
                return dp[i][M];
            }
            int min = INT_MAX;
            for (int j = 1; j <= 2*M; j++) {
                min = std::min(min, solve( i+j, std::max(j, M)));
            }
            return dp[i][M] = suff[i]-min;
        };
        solve(0, 1);
        return dp[0][1];
    }
};