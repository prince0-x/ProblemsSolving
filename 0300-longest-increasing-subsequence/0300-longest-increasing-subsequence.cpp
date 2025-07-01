class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for(int i=0;i<nums.size();i++){
            if(dp.empty() || nums[i]>dp.back()){
                dp.push_back(nums[i]);
            }else{
                int ind = lower_bound(dp.begin(), dp.end(),nums[i])-dp.begin();
                // cout<<i<<" "<<ind<<endl;
                dp[ind]= nums[i];
            }
        }
        return dp.size();
    }
};