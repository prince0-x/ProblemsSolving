class Solution {
public:
    vector<int>dp;
    int n;
   
    bool canReach(string s, int minJump, int maxJump) {
        n=(int)s.size();
        dp.assign(n, 0);
        dp[0]=1;
        int reachable=0;
        for(int i=1; i<n; i++){
            if(i-minJump >=0 && dp[i-minJump]){
                reachable++;
            }
            if(i-maxJump-1 >=0 && dp[i-maxJump-1]){
                reachable--;
            }
            dp[i]= (reachable >0 && s[i]=='0');
        }
        return dp[n-1];
    }
};