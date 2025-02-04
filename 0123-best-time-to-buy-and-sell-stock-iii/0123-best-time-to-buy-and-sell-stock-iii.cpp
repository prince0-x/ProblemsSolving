class Solution {
public:
//  int solve(int index, int buy, vector<int>&prices, int limit)
//     {
//         if(index==prices.size())return 0;
//         if(limit==0)return 0;
//         int profit=0;
//         if(buy)
//         {
//             profit=max(-prices[index]+solve(index+1, 0, prices,limit), 0 + solve(index+1, 1, prices,limit));
//         }
//         else{
//             profit= max(+prices[index]+solve(index+1, 1, prices,limit-1), 0 + solve(index+1, 0, prices,limit));
//         }
//         return profit;
//     }

  int solve1(int index, int buy, vector<int>&prices,int limit,vector<vector<vector<int>>>&dp)
    {
        if(index==prices.size())return 0;
        if(limit==0)return 0;

        if(dp[index][buy][limit]!=-1)return dp[index][buy][limit];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[index]+solve1(index+1, 0, prices,limit,dp), 0 + solve1(index+1, 1, prices,limit,dp));
        }
        else{
            profit= max(+prices[index]+solve1(index+1, 1, prices,limit-1,dp), 0 + solve1(index+1, 0, prices, limit,dp));
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
      return solve1(0, 1, prices, 2,dp);   
    }
};