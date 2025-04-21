class Solution {
public:
  vector<vector<int>>dp;
  int solve(int i, int j, vector<int>&arr){
      if(i>=j-1)return 0;
      if(dp[i][j] != -1)return dp[i][j];
      int ans =INT_MAX;
      for(int k =i+1;k<j;k++){
          ans=min(ans, solve(i, k, arr)+solve(k, j, arr)+ arr[j]-arr[i]);
      }
      return dp[i][j]=ans;
  }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0 );
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        dp.resize(m, vector<int>(m, -1));
        return solve(0, m-1, cuts);
    }
};