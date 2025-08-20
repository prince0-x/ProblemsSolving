class Solution {
public:
int n, m;
string s, t;
vector<vector<int>>dp;
    bool solve(int i, int j){
        if(i==0 && j==0){
            return true;
        }
        if(j==0){
            return false;
        }
        if(i==0){
            for(int ind= j-1;ind>=0;ind--){
                if(t[ind] != '*')return false;
            }
            return true;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        bool ans= false;
        if(s[i-1]==t[j-1] || t[j-1]=='?'){
            ans= solve(i-1, j-1);
        }
        else if(t[j-1]=='*'){
            ans=solve(i-1, j)||solve(i, j-1);
        }
        return dp[i][j]= ans;
    }
    bool isMatch(string st, string pt) {
        n= st.size(), m = pt.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        s=st, t=pt;
        return solve(n, m);
    }
};