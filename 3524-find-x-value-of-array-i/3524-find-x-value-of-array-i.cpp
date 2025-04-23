class Solution {
public:

    long long solve(int index, int required, int product, int k, vector<int>& arr, vector<vector<long long >>&dp) {

        if (index == arr.size()) return 0;
        if (dp[index][product +1 ]!= -1) return dp[index][product+1];
        long long take = 0, notTake = 0, count = 0;

        if (product == -1) {//not taken
            if (arr[index] == required) count = 1;
            take = count + solve(index + 1, required, arr[index], k, arr, dp);
            notTake = solve(index + 1, required, -1, k, arr, dp);
        } else {//if taken then append necesary
            int newProduct = (product * arr[index]) % k;
            if (newProduct == required) count = 1;
            take = count + solve(index + 1, required, newProduct, k, arr, dp);
        }

        return dp[index][product+1] = take + notTake;
    }

        vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);

        for (int& num : nums) {
            num %= k;
        }

        for (int required = 0; required < k; ++required) {
            vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
            ans[required] = solve(0, required, -1, k, nums, dp);
        }
        return ans;
    }
};