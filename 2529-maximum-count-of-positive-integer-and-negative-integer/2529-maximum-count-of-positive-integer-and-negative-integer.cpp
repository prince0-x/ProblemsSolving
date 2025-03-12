class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int index = lower_bound(nums.begin(), nums.end(), 0)-nums.begin();
        int index2= nums.size()-(upper_bound(nums.begin(), nums.end(), 0)-nums.begin());
        return max(index, index2);
    }
};