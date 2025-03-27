class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()>goal.size() || s.size()<goal.size())return false;
        string v=s+s;
        cout<<v<<" ";
        int ans = v.find(goal);
        if(ans==-1)return false;
        return true;
    }
};