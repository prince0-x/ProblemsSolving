class Solution {
public:
const int MOD=1e9+7;
int pre[10000][10][10], suf[10000][10][10], cnt[10]={0};
    int countPalindromes(string s) {
        int ans = 0, n =s.size();
            for(int i=0;i<n;i++)
            {
                int c = int(s[i]-'0');
                if(i>0)
                {
                    for(int j=0;j<10;j++)
                    {
                        for(int k =0;k<10;k++)
                        {
                            pre[i][j][k]=pre[i-1][j][k];
                            if(k==c)pre[i][j][k]+=cnt[j];
                        }
                    }
                }
                cnt[c]++;
            }

            memset(cnt, 0, sizeof(cnt));
            for(int i=n-1;i>=0;i--)
            {
                int c = int(s[i]-'0');
                if(i<n-1)
                {
                    for(int j=0;j<10;j++)
                    {
                        for(int k=0;k<10;k++)
                        {
                            suf[i][j][k]=suf[i+1][j][k];
                            if(k==c)suf[i][j][k]+=cnt[j];
                        }
                    }
                }
                cnt[c]++;
            }
            for(int i=2; i<=n-2;i++)
            {
                for(int j=0;j<10;j++)
                {
                    for(int k=0;k<10;k++)
                    {
                        ans = (ans+1LL*pre[i-1][j][k]*suf[i+1][j][k])%MOD;
                    }
                }
            }
            return ans;
    }
};