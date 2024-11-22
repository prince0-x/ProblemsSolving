class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xora=0;
        for(int i=0;i<nums.size()+1;i++)
        {
            xora^=i;
        }
        for(auto i:nums)xora^=i;
        return xora;
    }
};