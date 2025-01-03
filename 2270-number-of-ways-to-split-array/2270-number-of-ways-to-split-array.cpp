class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<long long int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        for(int i=0;i<n-1;i++)
        {
            long long int left,right;
            left = pref[i];
            right=pref[n-1]-left;
            if(left>=right)
            {
                count += 1;
            }
        }
        return count;
    }
};