class Solution {
public:

    int calculateMinimumHP(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();

        if(dp[n-1][m-1]>0){
            dp[n-1][m-1] = 1;
        }else{
            dp[n-1][m-1] = 1-dp[n-1][m-1];
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1; j>=0;j--){

                if(i==n-1 && j ==m-1)continue;
                int mini = INT_MAX;

                if(j+1 <m)mini = min(mini, dp[i][j+1]);
                if(i+1 <n)mini = min(mini, dp[i+1][j]);
                if(dp[i][j] >= mini)dp[i][j]=1;
                else dp[i][j]= mini - dp[i][j];
            }
        }
        return dp[0][0];
    }
};