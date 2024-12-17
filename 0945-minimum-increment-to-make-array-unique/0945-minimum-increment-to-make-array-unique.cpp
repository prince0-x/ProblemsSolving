class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ops = 0,n = nums.size(),y;
        y = nums[0];
        for(int i = 1; i < n ; i++)
        {
            if(nums[i] > y)
                y = nums[i];
            else{
                ops += (y-nums[i] + 1);
                y++;
            }
        }
        return ops; 
    }
};