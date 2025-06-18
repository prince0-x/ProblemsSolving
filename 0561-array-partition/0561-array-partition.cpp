class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int ans =0;
        for(int i =1;i<nums.size();i+=2){
            ans+=min(nums[i], nums[i-1]);
        }
        return ans;
    }
};