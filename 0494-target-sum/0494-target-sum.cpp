class Solution {
public:
    int rec(int index, int target, vector<int>&nums,vector<vector<int>>&dp){
        if(index==nums.size())return target==0;
        if(dp[index][target+1000]!=-1)return dp[index][target+1000];
        int ans=0;
        ans+=rec(index+1, target+nums[index], nums,dp);
        ans+=rec(index+1, target-nums[index], nums, dp);
       return dp[index][target+1000]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(), vector<int>(3002, -1));
        return rec(0, target, nums, dp);
    }
};