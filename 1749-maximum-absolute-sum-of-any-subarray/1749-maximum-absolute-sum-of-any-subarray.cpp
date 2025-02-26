class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax =0, currmin=0, gmax =nums[0], gmin = nums[0];
        for(auto i:nums)
        {
            currmax= max(currmax+i, i);
            currmin = min(currmin+i, i);
            gmax = max(gmax, currmax);
            gmin = min(gmin, currmin);
        }
        return max(abs(gmax), abs(gmin));
    }
};