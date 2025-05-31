class Solution {
public:
vector<vector<int>>dp;
    int solve(int i , int j, vector<int>&arr){
        if(i>j)return 0;
        if(dp[i][j]!= -1 )return dp[i][j];
        int ans = INT_MIN;
        for(int k =i; k<=j;k++){
            ans = max(ans, solve(i, k-1, arr)+solve(k+1, j, arr)+arr[i-1]*arr[k]*arr[j+1]);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int m = nums.size();
        dp.resize(m, vector<int>(m, -1));
        return solve(1, m-2, nums);
    }
};