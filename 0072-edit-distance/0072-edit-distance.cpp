class Solution {
public:
    int edit_distance(string a, string b, vector<vector<int>>&dp, int i=0, int j=0)
    {
    if(i==a.size() and j==b.size())return 0;
    if(i==a.size())return b.size()-j;
    if(j==b.size())return a.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans;
    if(a[i] != b[j])
    {
           ans = 1 + min(edit_distance(a, b,dp, i+1, j), min(edit_distance(a, b, dp, i, j+1), edit_distance(a, b, dp, i+1, j+1)));
    }
    else{
       ans = edit_distance(a, b,dp, i+1, j+1);
    }
    return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return edit_distance(word1, word2, dp);
    }
};