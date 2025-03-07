class Solution {
public:

    vector<int>copy(vector<int>p, int k, int x)
    {
        vector<int>v;
        for(int i=0;i<k;i++)
        {
            v.push_back(p[i]);
        }
        v.push_back(x);
        for(int i=k;i<p.size();i++)
        {
            v.push_back(p[i]);
        }
        return v;

    }
    vector<vector<int>> getp(vector<int>& nums, int i)
    {
        vector<vector<int>> ans;
        if(i ==nums.size()-1)
        {   
            ans.push_back({nums[i]});
            return ans;
        }
        vector<vector<int>> perms = getp(nums, i+1);
        for(int j =0;j<perms.size();j++)
        {
            for(int k=0;k<=perms[j].size();k++)
            {
                ans.push_back(copy(perms[j], k, nums[i]));
            }
        }
     return ans;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans =getp(nums,0);
        return ans;
    }
};