class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       map<int,int>m;
       for(auto i:nums)
       {
        m[i]++;
       }
       nums.clear();
       for(auto i:m)
       {
        nums.push_back(i.first);
       }
        return nums.size();
    }
};