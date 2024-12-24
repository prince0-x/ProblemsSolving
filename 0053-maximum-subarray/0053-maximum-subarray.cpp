class Solution {
public:
// kadanes algo
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN,sm = 0;
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
            sum=max(sum,sm);
            if(sm<0)
            {
                sm=0;
            }
        }
        return sum;
    }
};