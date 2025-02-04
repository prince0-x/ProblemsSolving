class Solution {
public:
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


