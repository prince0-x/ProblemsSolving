class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       bool ans = false;
       int n = nums.size();
       int val = INT_MAX;
       for(int i =0 ; i< n; ++i)
       {
        int sum =0;
        for(int j=i;j<n;++j)
        {
            sum+=nums[j];
            int len = j-i+1;
            if(len >=l and len <=r and sum>0)
            {
                val = min(val, sum);
                ans = true;
            }
        }
       }
       return ans ? val : -1;
    }
};