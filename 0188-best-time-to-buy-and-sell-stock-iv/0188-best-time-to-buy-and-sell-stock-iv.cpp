class Solution {
public:
     int solveT_opt(vector<int>&prices,int k)
    {
        int n= prices.size();
        vector<vector<int>>curr(2, vector<int>(k+1,0));
        vector<vector<int>>next(2, vector<int>(k+1,0));
       
        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy =0; buy<= 1; buy++)
            {
                for( int limit =1; limit <=k; limit++)
                {
                    if(buy)
                    {
                        curr[buy][limit]=max(-prices[ind]+next[0][limit], 0 + next[1][limit]);
                    }
                    else{
                        curr[buy][limit]= max(+prices[ind]+next[1][limit-1], 0 + next[0][limit]);           }
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveT_opt(prices,k);
    }
};