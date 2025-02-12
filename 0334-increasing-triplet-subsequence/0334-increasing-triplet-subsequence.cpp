class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int v1 = INT_MAX, v2 = INT_MAX;
        for(auto i:nums)
        {
            if(i<=v1)
            {
                v1=i;
            }
            else if(i<=v2)
            {
                v2= i;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};