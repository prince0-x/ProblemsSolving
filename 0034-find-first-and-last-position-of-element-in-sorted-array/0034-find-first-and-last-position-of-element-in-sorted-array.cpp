class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int d1=-1,d2=-1;
          int key=0;
        vector<int>p;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                if(key==0)
                {
                    d1=i;
                    key++;
                }
                d2=i;
            }
        }
        p.push_back(d1);
        p.push_back(d2);
        return p;
    }
};