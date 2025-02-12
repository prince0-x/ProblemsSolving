class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n,0), maxi(n,0);
        mini[0]=nums[0];
        maxi[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        {
            mini[i]=min(mini[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1], nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if((i-1)>0  && (i+1)<n &&nums[i]>mini[i-1] and nums[i]<maxi[i+1])return true;
        }
        return false;
    }
};