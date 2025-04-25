class Solution {
public:
int dp[19][1025][2][2];
int solve(int n, int index, bool tight, string s, int mask, bool leading_zero){
    if(index >=n) return 1;
    // cout<<mask<<" "<<endl;
    if(dp[index][mask][tight][leading_zero] != -1)return dp[index][mask][tight][leading_zero];
    int mini =0;
    int maxi = tight?s[index]-'0':9;
    int ans = 0;
    for(int i = mini; i<=maxi; i++){
      if(leading_zero || (mask&(1<<i))==0){ 
        ans+=  solve(n, index+1, tight && i==maxi, s,(leading_zero && i==0?  mask:mask |(1<<i)),(leading_zero && i==0) );
      }
    }


    return dp[index][mask][tight][leading_zero] = ans;
}
    int numDupDigitsAtMostN(int n) {
        memset(dp, -1, sizeof dp);
        string s= to_string(n);
        int m = s.size();
        return n - solve(m, 0, 1, s,0, 1)+1;
    }
};