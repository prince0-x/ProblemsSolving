class Solution {
    public:
    bool isMatch(string s, string p) {
       int  n = s.size(), m = p.size();
       vector<bool>dp(m+1,false);
       bool prev = false;
       dp[0]=true;
       for(int j = 1; j<= m; j++)
       {
        if(p[j-1]=='*')
        {
            dp[j]= dp[j-1];
        }
       }
       for(int i = 1; i<= n;i++)
       {
        prev = dp[0];
        dp[0]=false;
        for( int j = 1; j<= m; j++)
        {
            bool temp = dp[j];
            if(p[j-1]==s[i-1] or p[j-1]=='?')
            {
                dp[j]=prev;
            }
            else if (p[j-1]=='*')
            {
                dp[j]= dp[j] || dp[j-1];
            }
            else{
                dp[j]=false;
            }
            prev = temp;

        }
       }
       return dp[m];
    }
};
static const int __ =[](){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    return 0;
}();