class Solution {
public:
    int solve(int index, int buy, vector<int>&prices)
    {
        if(index==prices.size())return 0;
        int profit=0;
        if(buy)
        {
            profit=max(-prices[index]+solve(index+1, 0, prices), 0 + solve(index+1, 1, prices));
        }
        else{
            profit= max(+prices[index]+solve(index+1, 1, prices), 0 + solve(index+1, 0, prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
    int i=0,j=0,sum=0;
    int Min=INT_MAX;
    while(i<prices.size())
    {
       if(Min<prices[i])
       {
        sum+=(prices[i]-Min);
        Min=prices[i];
       }
        else
        {
            Min=prices[i];
        }
       i++;
    }
    return sum;
    }
};


