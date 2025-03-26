class Solution {
public:
    string reverseWords(string s) {
        string temp="",ans="";
        for(int i =0;i<s.size();i++){
            if(s[i]==' ')
            {
                if(temp.size()==0)continue;
                else {ans= temp+" "+ans; temp="";}
            }else{
                temp+=s[i];
            }
        }
        if(temp.size()>0)ans=temp+" "+ans;

        ans.pop_back();
        return ans;
    }
};