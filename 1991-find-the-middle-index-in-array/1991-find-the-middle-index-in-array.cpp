class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
         int n=nums.size();
        long long int rsum=0,lsum=0;
        for(int i=0; i<n;i++)
              rsum+=nums[i];
        lsum=0;
        for(int i=0;i<n;lsum+=nums[i++])
        {
               if(lsum*2==rsum-nums[i])return i;
        }
        return -1;
    }
};