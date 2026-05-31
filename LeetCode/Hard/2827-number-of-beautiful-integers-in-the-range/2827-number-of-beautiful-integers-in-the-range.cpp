class Solution {
public:
    int dp[20][2][2][20][20][50];
    int k;
    
    int solve(string &s, int n, int ind, int tight, int lz, int cnteven, int cntodd, int rem){
        if(ind == n){
            return (cnteven == cntodd && rem==0);
        }
        if(dp[ind][tight][lz][cnteven][cntodd][rem] != -1){
            return dp[ind][tight][lz][cnteven][cntodd][rem];
        }
        int limit = tight ? s[ind]-'0':9;
        int ways = 0;
        for(int d=0; d<=limit; d++){
            int ntight = tight && (d== limit);
            int nlz =lz &&(d==0);
            if(nlz){
                ways +=solve(s, n, ind+1, ntight, nlz, 0, 0, 0);
            }else{
                int nrem = (rem*10 + d)%k;
                if(d%2==0){
                    ways +=solve(s, n, ind+1, ntight, nlz, cnteven+1, cntodd, nrem);
                }else{
                    ways +=solve(s, n, ind+1, ntight, nlz, cnteven, cntodd+1, nrem);
                }
            }
        }
        return dp[ind][tight][lz][cnteven][cntodd][rem]= ways;
    }
    int numberOfBeautifulIntegers(int low, int high, int K) {
        string h = to_string(high);
        string l = to_string(low-1);
        k=K;
        int n1 = (int)h.size();
        int n2 = (int)l.size();
        memset(dp, -1, sizeof dp);
        int hans=solve(h, n1, 0, 1, 1, 0, 0, 0);
        memset(dp, -1, sizeof dp);
        int lans= solve(l, n2, 0, 1, 1, 0, 0, 0);
        return hans-lans;
    }
};