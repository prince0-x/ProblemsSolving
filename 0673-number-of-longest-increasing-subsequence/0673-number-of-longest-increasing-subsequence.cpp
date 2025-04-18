class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0)return 0;
        vector<int>dp(nums.size(), 1), count(nums.size(), 1);
        int val =1;
        for(int i=1;i<nums.size();i++){
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=1+dp[j];
                        count[i]=0;
                    }
                    if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
            val = max(val, dp[i]);
        }

        int  ans=0;
        for(int i =0;i<nums.size();i++){
            if(dp[i]==val){
                ans+=count[i];
            }
        }
        return ans;
        
    }
};