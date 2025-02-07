class Solution {
public:
string print_lcs(string &s)
{
    if(s.size()<=1)return s;
    int m = s.size();
    vector<vector<int>>dp(m, vector<int>(m, 0));

    int ans =1, lastIndex=0, initindex=0;

    for(int i=0; i<m;i++)
    {
        for(int j=0; j<i;j++)
        {
                if(s[i]==s[j]  and (i-j <= 2 or dp[j+1][i-1]))
                {
                    dp[j][i]=1;
                    if(i-j+1 > ans)
                    {
                        ans= i-j+1;
                        lastIndex = i;
                        initindex = j;
                    }
                }
        }
    }
    return s.substr(initindex,lastIndex-initindex+1);  
}
    string longestPalindrome(string s) {
      return print_lcs(s);
    }
};