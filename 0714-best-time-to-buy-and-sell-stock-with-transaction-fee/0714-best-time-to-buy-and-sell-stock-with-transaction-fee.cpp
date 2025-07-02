class Solution {
public:
   int solve3( vector<int>&prices, int fee)
    {
        int n = prices.size(), profit =0;
        vector<int>curr(2,0);
        vector<int>next(2,0);

        for(int index=n-1; index>=0;index--)
        {
            for(int buy =0; buy<=1; buy++)
            {
                if(buy)
                {
                    profit = max(-prices[index]+ next[0], 0 + next[1]);
                }
                else
                {
                    profit = max(+prices[index] + next[1]-fee, 0 + next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
  
        // return solve3(prices,fee);

        int hold = -prices[0]; // Profit if we hold a stock
        int notHold = 0;       // Profit if we don’t hold a stock

        for (int i = 1; i < prices.size(); i++) {
            hold = max(hold, notHold - prices[i]); // Update holding state
            notHold = max(notHold, hold + prices[i] - fee); // Update not-holding state
        }

        return notHold;
    }
};