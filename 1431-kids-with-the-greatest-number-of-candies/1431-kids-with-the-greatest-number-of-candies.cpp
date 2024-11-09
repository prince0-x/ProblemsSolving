class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a, int e) {
        vector<bool>ans;
        int maxi = *max_element(a.begin(),a.end());
        for(auto i:a)
        {
            if(i+e >= maxi)
            {
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};