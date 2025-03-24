class Solution {
public:
vector<vector<string>>res; 
  bool ispalindrome(string s){
    int n = s.size();
    for(int i =0;i<n/2;i++){
        if(s[i]!=s[n-i-1])return false;
    }
    return true;
  }
 
void sve(int index, string s, vector<string>&temp)
{
    if(index == s.size()){
        res.push_back(temp);
        return ;
    }

    for(int i = index;i<s.size();i++)
    {
        string ts = s.substr(index, i-index+1);
        if(ispalindrome(ts)){
            temp.push_back(ts);
            sve(i+1,s, temp);
            temp.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<string>temp;
    sve(0,s,temp);
    return res;
    }
};