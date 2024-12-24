class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        int n = nums.size();
        for(int i:nums)m[i]++;
        for(auto i:m){
            if(i.second>n/3)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};