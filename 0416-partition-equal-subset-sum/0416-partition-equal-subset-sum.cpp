class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)return false;
        sum /=2;
        vector<bool>dp(sum+1, false);
        dp[0] = true;
        for(auto num:nums){
            for(int i = sum;i>=num;i--){
                dp[i] = dp[i-num]||dp[i];
            }
        }
        return dp[sum];
    }
};