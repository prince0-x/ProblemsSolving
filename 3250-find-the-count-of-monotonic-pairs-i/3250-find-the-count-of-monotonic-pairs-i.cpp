class Solution {
public:
    const int mod = 1e9 + 7;

    int rec(int i, int prev, int n, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == n) return 1;
        if (dp[i][prev] != -1) return dp[i][prev];

        int res = 0;
        
       
        for (int j = prev; j <= nums[i]; ++j) {
            if(i==0 ||(nums[i-1]-prev >= nums[i]-j)){
                res = (res + rec(i + 1, j, n, nums, dp)) % mod;
            }
        }

        return dp[i][prev] = res;
       
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2001, vector<int>(51, -1));
        return rec(0, 0, n, nums, dp);
    }
};
