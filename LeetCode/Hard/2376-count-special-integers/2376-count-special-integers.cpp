class Solution {
public:
    int dp[12][2][2][1024];
    int n;
    string s;
    int solve(int ind, int tight, int lz, int mask){
        if(ind == n){
            return lz ? 0 : 1;
        }
        if(dp[ind][tight][lz][mask] != -1){
            return dp[ind][tight][lz][mask];
        }
        int limit = tight ? s[ind]-'0' : 9;
        int ways =0;
        for(int d=0; d<= limit; d++){
            int ntight = tight && (d==limit);
            int nlz = lz&&(d==0);
            if(lz && d==0){
                ways +=solve(ind+1, ntight, nlz, mask);
            }else{
                if((mask &(1<<d) )!= 0){
                    continue;
                }else{
                    int nmask= mask|(1<<d);
                    ways+= solve(ind +1, ntight, nlz, nmask);
                }
            }
        }
        return dp[ind][tight][lz][mask]= ways;
    }
    int countSpecialNumbers(int N) {
        s= to_string(N);
        n= (int)s.size();
        memset(dp, -1, sizeof dp);
        return solve(0, 1, 1, 0);
    }
};