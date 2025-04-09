class Solution {
public: 
bool check(int n, int len){
    if(len == 1)return n>0 and n<=9;

    return n>=10 and n<=26;
}
int solve(int index, string&s, int n, vector<int>&dp){
    if(index==n)return 1;
    if(s[index]=='0')return 0;
    if(dp[index] != -1)return dp[index];
    int ans = 0;

    if(check(s[index]-'0', 1)){
        ans+=solve(index+1, s, n, dp);
    }
    if( index < n-1 && check((s[index]-'0')*10 + s[index+1]-'0', 2)){
        ans+=solve(index+2, s, n, dp);
    }
    return  dp[index] = ans;
}
    int numDecodings(string s) {

        int n = s.size();
        vector<int>dp(n,-1);
        return solve(0, s, n, dp);
        
    }
};