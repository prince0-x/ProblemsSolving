class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;          
        int val = INT_MAX,sum=0;          
        for(int i=0 ; i<nums.size(); i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                val = min(val, i-j+1);
                sum-=nums[j];
                j++;
            }
        }
    return val!=INT_MAX ? val : 0; 

        
    }
};