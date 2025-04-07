class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2)return false;
       int  k =sum/2;
        unordered_map<int,int>m;
        m[0]=1;
        int cnt=0,n=nums.size();
        sum=0;
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