class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=nums[0], maxans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=nums[i-1])
            {
                ans=nums[i];
            }else{
                ans+=nums[i];
            }
            maxans=max(maxans,ans);
        }
        return maxans;
    }
};