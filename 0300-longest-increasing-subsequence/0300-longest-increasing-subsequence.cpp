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
       vector<int>ans;
       for(auto i :nums){
          int ind = lower_bound(ans.begin(), ans.end(), i)-ans.begin();
          if(ind != ans.size())ans[ind] = i;
          else ans.push_back(i);
       }
       for(auto i:ans)cout<<i<<" ";
       return ans.size();
    }
};