class Solution {
public:
int solve(int i, bool buy, vector<int>&prices, int count,vector<vector<vector<int>>>&dp){
        if(i==prices.size())return 0;
        if(count==0)return 0;
        if(dp[i][buy][count] != -1)return dp[i][buy][count];

        int ans =0;
        if(buy){
            ans=max((-prices[i])+solve(i+1, 0, prices,count,dp), 0+solve(i+1,1,prices,count,dp));
        }else{
           ans=max(prices[i]+solve(i+1, 1, prices, count-1,dp),0+solve(i+1,0,prices,count,dp));
        }
        return dp[i][buy][count] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0, 1,prices,k,dp);
    }
};