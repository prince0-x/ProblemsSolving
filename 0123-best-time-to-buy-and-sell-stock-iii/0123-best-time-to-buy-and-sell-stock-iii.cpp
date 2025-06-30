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

//   int solve1(int index, int buy, vector<int>&prices,int limit,vector<vector<vector<int>>>&dp)
//     {
//         if(index==prices.size())return 0;
//         if(limit==0)return 0;

//         if(dp[index][buy][limit]!=-1)return dp[index][buy][limit];
//         int profit=0;
//         if(buy)
//         {
//             profit=max(-prices[index]+solve1(index+1, 0, prices,limit,dp), 0 + solve1(index+1, 1, prices,limit,dp));
//         }
//         else{
//             profit= max(+prices[index]+solve1(index+1, 1, prices,limit-1,dp), 0 + solve1(index+1, 0, prices, limit,dp));
//         }
//         return dp[index][buy][limit]=profit;
//     }
    // int solveT(vector<int>&prices)
    // {
    //     int n= prices.size();
    //     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
    //     for(int ind = n-1; ind >= 0; ind--)
    //     {
    //         for(int buy =0; buy<= 1; buy++)
    //         {
    //             for( int limit =1; limit <=2; limit++)
    //             {
    //                 if(buy)
    //                 {
    //                     dp[ind][buy][limit]=max(-prices[ind]+dp[ind+1][0][limit], 0 + dp[ind + 1][1][limit]);
    //                 }
    //                 else{
    //                     dp[ind][buy][limit]= max(+prices[ind]+dp[ind+1][1][limit-1], 0 + dp[ind+1][0][limit]);           }
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }
    //  int solveT_opt(vector<int>&prices)
    // {
    //     int n= prices.size();
    //     vector<vector<int>>curr(2, vector<int>(3,0));
    //     vector<vector<int>>next(2, vector<int>(3,0));
       
    //     for(int ind = n-1; ind >= 0; ind--)
    //     {
    //         for(int buy =0; buy<= 1; buy++)
    //         {
    //             for( int limit =1; limit <=2; limit++)
    //             {
    //                 if(buy)
    //                 {
    //                     curr[buy][limit]=max(-prices[ind]+next[0][limit], 0 + next[1][limit]);
    //                 }
    //                 else{
    //                     curr[buy][limit]= max(+prices[ind]+next[1][limit-1], 0 + next[0][limit]);           }
    //             }
    //         }
    //         next = curr;
    //     }
    //     return next[1][2];
    // }
    // int maxProfit(vector<int>& prices) {
        
    //   return solveT_opt(prices);   
    // }
      int maxProfit(vector<int>& prices) {
    int sellTwo = 0;
    int holdTwo = INT_MIN;
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (const int price : prices) {
      sellTwo = max(sellTwo, holdTwo + price);
      holdTwo = max(holdTwo, sellOne - price);
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellTwo;
  }
};