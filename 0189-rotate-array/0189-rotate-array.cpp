class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>arr(nums.begin(),nums.end());
        k=k%n;
        for(int i=0;i<k;i++)
        {
            nums[i]=nums[n-k+i];
        }
        for(int i=k;i<n;i++)
        {
            nums[i]=arr[i-k];
        }
    }
};