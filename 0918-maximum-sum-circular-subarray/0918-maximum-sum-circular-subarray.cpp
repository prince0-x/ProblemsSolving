class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int curMax =0, curMin =0, gMax = nums[0], gMin = nums[0], sum =0;
       for(auto i: nums)
       {
          curMax = max(curMax + i, i);
          curMin = min(curMin + i, i);
          gMax = max(gMax, curMax);
          gMin = min(gMin, curMin);
          sum+= i;
       }
       if(gMax > 0)
       {
        return max(gMax, sum - gMin);
       }
       return gMax;
    }
};