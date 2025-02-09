class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans, cnt=0, n=nums.size();
         unordered_map<int, int>mp;
         for(int i=0;i<n;i++)
         {
             int val = nums[i]-i;
             cnt+=mp[val];
             mp[val]++;
         }
         

        ans = (n*(n-1))/2-cnt;
        return ans;
    } 
};