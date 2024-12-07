class Solution {
public:
    int numWaterBottles(int nums,int num) {
        int ans=nums;
        while(nums/num>0)
        {
            ans+=nums/num;
            nums=nums/num + nums%num;
        }
        return ans;

    }
};