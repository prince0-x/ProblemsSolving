class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       bool ans = false;
       int val = INT_MAX;
       int n = nums.size();
       vector<int>pref(n+1,0);
       for(int i =0; i<n;i++){
        pref[i+1] = pref[i]+nums[i];
       }
       for(int i=l ;i<=r;i++)
       {
        for( int j =0;j+i<=n;j++)
        {
            int sum = pref[i+j]-pref[j];
            if(sum>0)
            {
                val=min(val,sum);
                ans=true;
            }
        }
       }
       return ans ? val : -1;
    }
};