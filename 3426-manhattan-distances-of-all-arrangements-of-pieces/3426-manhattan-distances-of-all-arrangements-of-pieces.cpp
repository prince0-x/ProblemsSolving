class Solution {
public:
const int MOD=1e9+7;
    long long combination(long long a, long long b)
    {
        if(b>a)return 0;
        long long n=1,d=1;
        for(long long i=0;i<b;++i)
        {
            n=n*(a-i)%MOD;
            d=d*(i+1)%MOD;
        }
        long long n_inv=1, exp=MOD-2;
        while(exp)
        {
            if(exp%2)n_inv=n_inv*d%MOD;
            d=d*d%MOD;
            exp/=2;
        }
        return n*n_inv%MOD;
    }
    int distanceSum(int m, int n, int k) {
        long long base = combination(m*n-2, k-2), res=0;
        for( int i=1; i<n;++i)
        {
            res = (res+1LL*i*(n-i)%MOD*m%MOD*m%MOD)%MOD;
        }
        for( int i=1; i<m;++i)
        {
            res = (res+1LL*i*(m-i)%MOD*n%MOD*n%MOD)%MOD;
        }
        return res*base%MOD;
    }
};