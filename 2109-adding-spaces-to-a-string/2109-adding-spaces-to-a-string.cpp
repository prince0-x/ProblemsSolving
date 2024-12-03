class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string ans="";
    for(auto i:spaces)
    {
         ans+=s.substr(j,i-j)+" " ; 
         j=i;
    }
    ans+=s.substr(j);
     return ans;
    }
};