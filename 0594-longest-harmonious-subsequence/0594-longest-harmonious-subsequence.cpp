class Solution {
public:
    int findLHS(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int i=0, j=1, ans=0;
        while(j<nums.size())
        {
            if(nums[j]-nums[i]==1)
            {
            	ans = max(ans, j-i+1);
            }
            while(nums[j]-nums[i]>1)
            {
            	++i;
            }
            	++j;
        }
        // cout<<ans<<endl;
        return ans;
    }
};

static const int __ =[]()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    return 0;
}();