class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans =0, e = 0;
        for(auto n:nums){
            ans+=max(0, e-n+1);
            e = max(e+1,n);
        }
        return ans;
    }
};