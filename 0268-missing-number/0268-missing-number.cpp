class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1=0,sum2=0,n=nums.size();
        sum1=(n*(n+1))/2;
        for(auto i:nums)
        {
            sum2+=i;
        }
        return sum1-sum2;
    }
};