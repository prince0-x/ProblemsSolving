class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(auto &i:nums){
            while(nums[i-1] != i){
                swap(nums[i-1], i);
            }
        }
        for(int i = 1; i <= size(nums); i++)
            if(i != nums[i-1]) ans.push_back(i);
        return ans;
    }
};