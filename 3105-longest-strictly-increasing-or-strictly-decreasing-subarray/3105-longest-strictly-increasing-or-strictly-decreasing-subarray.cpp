class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int il = 1, dl = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                il++;
                inc = max(inc, il);
                dl = 1;
            } else if (nums[i] > nums[i + 1]) {
                dl++;
                dec = max(dec, dl);
                il = 1;
            } else {
                il = 1;
                dl = 1;
            }
        }
        return max(inc, dec);

    }
};