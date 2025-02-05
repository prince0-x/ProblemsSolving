class Solution {
    public:
    bool m(string s, string p)
    {
       int  m1 = s.size();
       int  n = p.size();
       vector<vector<int>>dp(n+1,vector<int>(m1+1,0));
       dp[0][0]=1;
       for(int i=1; i<=n;i++)
       {
        int f =1;
            for(int k=0; k<=i-1;k++)
            {
                if(p[k]!='*')
                {
                    f=0;
                    break;
                }
            }
        dp[i][0]=f;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j =1; j<=m1;j++)
            {
                if(p[i-1]==s[j-1] or p[i-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m1];
       
    }
    bool isMatch(string s, string p) {
      return m(s, p);
    }
};
