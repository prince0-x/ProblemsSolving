class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n+1, vector<unsigned long long>(amount+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int curr =0 ; curr<=amount; curr++){
                if(i>0 &&curr-coins[i-1]>=0){
                    dp[i][curr]= dp[i-1][curr]+dp[i][curr-coins[i-1]];
                }else{
                    dp[i][curr] = dp[i - 1][curr];
                }
            }
        }
        return dp[n][amount];
    }
};