using ll = long long;
class Solution {
public:
    ll dp[16][2][10];
    bool path[16];
    ll dfs(ll i,ll tight,ll last,string &s)
    {
        if(i==16)return 1;
        if(dp[i][tight][last]!=-1)
        {
            return dp[i][tight][last];
        }
        int lim;
        if(tight==0)lim=9;
        else lim=s[i]-'0';
        ll ans=0;
        for(ll d=0;d<=lim;d++)
            {
                if(path[i])
                {
                    if(d>=last)
                    {
                        ans+=dfs(i+1,tight&&(d==lim),d,s);
                    }
                }
                else
                {
                    ans+=dfs(i+1,tight&&(d==lim),last,s);
                }
            }
        return dp[i][tight][last]=ans;
    }
    ll solve(ll n)
    {
        string s=to_string(n);
        ll l=s.size();
        string t(16-l,'0');
        s=t+s;
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,0,s);
    }
    long long countGoodIntegersOnPath(long long l, long long r, string dir) {
        memset(path,0,sizeof(path));
        int ro=0,c=0;
        path[0]=true;
        for(int i=0;i<dir.size();i++)
            {
                if(dir[i]=='D')ro++;
                else c++;
                path[ro*4+c]=true;
            }
        return solve(r)-solve(l-1);
    }
};