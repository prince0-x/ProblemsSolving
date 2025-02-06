class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans=0;
        unordered_map<int ,int>m;
        for(int i=0;i<nums.size(); i++)
        {
            for(int j =i+1; j< nums.size();j++)
            {
                m[nums[i]*nums[j]]++;
            }
        }
        for(auto [f,s]:m)
        {
            if(s>=2)
            {
                ans+=s*(s-1)*4;
            }
        }
        return ans;
    }
};