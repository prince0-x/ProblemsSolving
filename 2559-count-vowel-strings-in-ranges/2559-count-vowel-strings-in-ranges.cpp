class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pref,ans;
        for(auto s:words)
        {
            char x=s.front(),y=s.back();
            if( (0x208222>>(x&0x1f))&1 and  (0x208222>>(y&0x1f))&1)pref.push_back(1);
            else pref.push_back(0);
        }
        for(int i=1;i<n;i++)
        {
            pref[i]+=pref[i-1];
        }
        for(auto q:queries)
        {
             int x=q[0],y=q[1];
             ans.push_back((pref[y] - (x > 0 ? pref[x - 1] : 0)));
        }
        return ans;
    }
};