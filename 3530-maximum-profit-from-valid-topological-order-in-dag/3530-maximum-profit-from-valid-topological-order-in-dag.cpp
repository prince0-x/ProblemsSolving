class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int>need(n, 0), dp(1<<n, -1);
        for(auto &i:edges)
        {
            int u=i[0], v=i[1];
            need[v]|=(1<<u);
        }
        dp[0] =0;
        for(int i=0;i<(1<<n);++i)
        {
            if(dp[i] ==-1)continue;
            int pos = __builtin_popcount(i)+1;
            for(int j =0;j<n;++j)
            {
                if(((i>>j)&1) ==0 && (i&need[j])==need[j]){
                    int mask2=i|(1<<j);
                    dp[mask2] = max(dp[mask2], dp[i]+score[j]*pos);
                }
            }
        }
        return dp[(1<<n)-1];

    }
};