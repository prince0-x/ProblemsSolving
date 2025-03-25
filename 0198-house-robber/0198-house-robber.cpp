class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
       vector<int>dp(n);
       dp[n-1]=nums[n-1];

       if(n-2>=0)dp[n-2]=max(nums[n-2],dp[n-1]);


       for(int i = n-3;i>=0;i--)
       {
        dp[i]=max(dp[i+1], dp[i+2]+nums[i]);
       }
       return dp[0];
    }
};