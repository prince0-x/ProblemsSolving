class Solution {
public:
void getp(vector<int>& nums, int i,set<vector<int>>&ans)
    {
        if(i ==nums.size()-1)
        {   
            ans.insert(nums);
            return ;
        }
        
        for(int j =i;j<nums.size();j++)
        {
            swap(nums[i], nums[j]);
            getp(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>>s;
        getp(nums, 0, s);
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};