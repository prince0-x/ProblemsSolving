class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        unordered_map<long long, long long> pre;

        long long res = nums[0];
        long long prefix = 0;
        long long low = 0;
        pre[0] = 0;

        for (auto num : nums) {
            prefix += num;
            res = max(res, prefix - low);

            if (num < 0) {
                if (pre.count(num)) {
                    pre[num] = min(pre[num], pre[0]) + num;
                } else {
                    pre[num] = pre[0] + num;
                }
                low = min(low, pre[num]);
            }

            pre[0] = min(pre[0], prefix);
            low = min(low, pre[0]);
        }

        return res;
    }
};
