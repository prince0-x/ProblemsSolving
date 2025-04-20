class Solution {
public:
   vector<vector<int>>dp;
   bool fn(int i, int j, string s1, string s2, string s3){
    if(i==s1.size() && j == s2.size()) return true;
    int k = i+j;
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans=0;
    if(i<s1.size() && s1[i] == s3[k]){
        ans|=fn(i+1, j, s1, s2, s3);
    }
    if(j<s2.size() && s2[j] == s3[k]){
        ans|=fn(i, j+1, s1, s2, s3);
    }
    return ans;
   }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return 0;
        dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));
        return fn(0, 0, s1, s2, s3);
    }
};