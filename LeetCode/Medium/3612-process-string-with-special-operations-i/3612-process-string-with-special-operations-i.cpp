class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto c:s){
            if(c=='#'){
                ans=ans+ans;
            }else if(c=='%'){
                if(ans.size())reverse(ans.begin(), ans.end());
            }else if(c=='*'){
                if(ans.size())ans.pop_back();
            }else ans+=c;
        }
        return ans;
    }
};