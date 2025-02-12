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
            // cout<<mini[i]<<" ";
        }
        // cout<<"\n";
        for(int i=n-2;i>=0;i--)
        {
            maxi[i]=max(maxi[i+1], nums[i]);
            // cout<<maxi[i]<<" ";
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mini[i] and nums[i]<maxi[i]) return true;
        }
        return false;
    }
};