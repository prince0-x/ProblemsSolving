class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int sum=0,cnt=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(m.find(sum-k)!=m.end())
            {
                cnt+=m[sum-k];
            }
            m[sum]++;
        }
        return cnt;
    }
};