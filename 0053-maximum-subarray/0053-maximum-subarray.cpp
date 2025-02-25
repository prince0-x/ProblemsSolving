class Solution {
public:
// kadanes algo
    int maxSubArray(vector<int>& nums) {
        int curSum =0 , max_sum = INT_MIN;
        for (int val : nums){
            curSum += val;
            max_sum = max(curSum,max_sum);
            if(curSum<0){
                curSum = 0;
            }
        }
        return max_sum;
    }
};