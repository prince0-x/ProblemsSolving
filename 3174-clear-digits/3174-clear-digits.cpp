class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto x:s)
        {
            if(!isdigit(x))ans+=x;
            else if(ans.size()>0)ans.pop_back();
        }
        return ans;
    }
};