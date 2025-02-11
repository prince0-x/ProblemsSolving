class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto x:s)
        {
            if(!isdigit(x))ans+=x;
            else ans.pop_back();
        }
        return ans;
    }
};