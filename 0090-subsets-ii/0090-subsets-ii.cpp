class Solution {
public:
 vector<vector<int>>ans;
 unordered_map<int, int>freq;
 
void solve( vector<int>&nums, int index, vector<int>&temp)
{
    if(index==nums.size())
    {
      ans.push_back(temp);
      return;
    }
    for(int i =0; i<=freq[nums[index]];i++)
    {
       for(int j =0;j<i;j++) temp.push_back(nums[index]);
        solve(nums, index+1, temp);
        for(int j =0;j<i;j++)temp.pop_back();
    }
    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     
     vector<int>arr;
     for(auto i:nums)
     {
        freq[i]++;
     }
     for(auto [k,v]:freq)
     {
        arr.push_back(k);
     }
     vector<int>temp;
      solve(arr,0, temp);
      return ans;
    }
};