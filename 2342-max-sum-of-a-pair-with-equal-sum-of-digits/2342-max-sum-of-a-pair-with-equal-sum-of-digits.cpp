class Solution {
public:
int dig(int n)
{
    int ans =0;
    while(n>0)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int>mp;
        int ans =INT_MIN;
        for(auto i: nums)
        {
            int val = dig(i);
            if(mp.find(val)!=mp.end())
            {
                ans = max(ans, mp[val]+i);
            }
            mp[dig(i)]=max(i,mp[val]);
        }
        if(ans<0)return -1;
        return ans;
    }
};