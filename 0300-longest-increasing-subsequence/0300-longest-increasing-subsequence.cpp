class Solution {
public:
int solve(vector<int>&nums, int index, int prevind, vector<vector<int>>&dp){
    if(index == nums.size())return 0;
    if(dp[index][prevind+1]!=-1)return dp[index][prevind+1];
    int notTake = solve(nums, index+1, prevind, dp);
    int take = 0;
    if(prevind ==-1 || nums[index]>nums[prevind] )
    {
        take = 1+solve(nums, index+1, index, dp);
    }
    return dp[index][prevind+1]= max(take, notTake);
}
    int lengthOfLIS(vector<int>& nums) {
       if(nums.size()==0)return 0;
       vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1, -1));
       return solve(nums,0,-1 , dp); 
    }
};