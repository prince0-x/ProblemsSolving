class Solution {
public:
long long  dp[100001][10][3];
int n;
string s;
    long long solve(int i, int sum, int st, int &d)
    {
        if(st==2)
        {
            if(sum==0)return 1;
            return 0;
        }
        if(i==n)return 0;

        if(dp[i][sum][st] != -1)return dp[i][sum][st];
        long long ans=0;
        int x = (int)(s[i]-'0');
        if(st==0)
        {
            ans+=solve(i+1, sum, st, d);
            ans+=solve(i+1,(sum*10+x)%d, 1, d);
            if(d==x)
            {
                ans+=solve(i+1, (sum*10+x)%d, 2, d);
            }
        }
        if(st==1)
        {
            if(d==x)
            {
                ans+=solve(i+1, (sum*10+x)%d, 2, d);
            }
            ans+=solve(i+1, (sum*10+x)%d, 1, d);
        }
        return dp[i][sum][st]=ans;
    }
    long long countSubstrings(string t) {
        long long ans =0;
        s =t;
        n=(int)s.size();
        for(int d=1;d<=9;d++)
        {
            for(int i=0;i<=n ;i++)
            {
                for(int j=0;j<10;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        dp[i][j][k]=-1;
                    }
                }
            }
            ans+=solve(0,0,0,d);
        }
        
        return ans;
    }
};