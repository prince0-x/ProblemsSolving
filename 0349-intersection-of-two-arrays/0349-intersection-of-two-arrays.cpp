class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s,s2;
        vector<int>ans;
        for(auto i:nums1)
        {
            s.insert(i);
        }
        for(auto i:nums2)
        {
            if(s.find(i)!=s.end())
            {
                s2.insert(i);
            }
        }
        for(auto i:s2)
        {
            ans.push_back(i);
        }
        return ans;
    }
};