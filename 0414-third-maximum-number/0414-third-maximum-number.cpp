class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>s(nums.begin(), nums.end());
        
        vector<int>arr(s.begin(), s.end());
        int n = arr.size();

        return arr.size()>2?arr[n-3]:arr.back();
    }
};