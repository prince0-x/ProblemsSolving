class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> mf;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        for (int num : nums) {
            if (num != 0) {
                mf.push_back(num);
            }
        }
        while (mf.size() < n) {
            mf.push_back(0);
        }

        return mf;
    }
};