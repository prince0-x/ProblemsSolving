class Solution {
public:
    vector<vector<int>>dp;
    vector<int>dp2;
    int n;

    int f(int i, string s){
        if(i>=n)return 0;
        if(dp2[i]!=-1)return dp2[i];
        dp2[i]=INT_MAX;
        for(int j=i; j<n;j++){
            if(dp[i][j])dp2[i]=min(dp2[i], 1+f(j+1,s));
        }
        return dp2[i];
    }
    int minCut(string s) {
        n = s.size();
        dp2.resize(n,-1);
        dp.resize(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[i][j]=1;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j]=(s[i] == s[j]) && dp[i+1][j-1];
            }
        }

       return f(0,s)-1;
    }
};