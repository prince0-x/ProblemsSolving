class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<int>dp(n, 1), par(n), lis;
      int index = 0, ans=1;
      for(int i =1; i<n;i++){
            for(int j =0; j<i;j++){
                  if(nums[i]> nums[j]){
                        if(dp[i]< 1+dp[j]){
                            dp[i]=1+dp[j];
                            par[i]=j;
                        }
                  }
            }
            if(dp[i]>ans){
                ans = dp[i];
                index= i;
            }
      }
      
      
      while(par[index]!=index){
        lis.push_back(nums[index]);
        index = par[index];
      }
      lis.push_back(nums[index]);
      for(auto i:lis)cout<<i<<" ";
      
      return *max_element(dp.begin(), dp.end());
    }
};