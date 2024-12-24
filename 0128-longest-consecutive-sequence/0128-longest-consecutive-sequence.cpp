class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;

    for(auto i:s)
    {
        if(s.find(i-1)==s.end()){
            int current_num=i;
            int current_length=1;
            while(s.find(current_num+1)!=s.end())
            {
                current_num++;
                current_length++;
            }
            ans =max(ans,current_length);
        }
    }

    return ans;
    }
};