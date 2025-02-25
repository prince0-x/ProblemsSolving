class Solution {
public:
// kadanes algo
    int maxSubArray(vector<int>& nums) {
        int sum=0, maxans =INT_MIN;
        for(auto i: nums)
        {
            sum=max(sum+i, i);
            maxans = max(maxans, sum);
        }
        return maxans;
    }
};