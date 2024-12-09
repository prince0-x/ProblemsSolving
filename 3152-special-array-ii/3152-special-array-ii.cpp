class Solution {
public:
   

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool>ans;
        vector<int>pref(n,0);
        for(int i=1;i<n;i++)
        {
            pref[i]=pref[i-1];
            if(((nums[i-1]+1)&1 and (nums[i]+1)&1) or( nums[i-1]&1 and nums[i]&1))pref[i]++;
        }
        for(auto & q:queries)
        {
            int l = q[0], r = q[1];
            int spl = pref[r] - (l > 0 ? pref[l]: 0);
            ans.push_back(spl==0);
        }
        return ans;
    }
};