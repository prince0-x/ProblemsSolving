class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& ss, vector<vector<int>>& ts) {

        vector<vector<int>>dp(k+1, vector<int>(n, 0));

        for(int day =1 ; day<=k; day++){
            for(int city=0;city<n;city++){
                dp[day][city] = ss[day - 1][city]+dp[day-1][city];
                int res =0;
                for(int td =0;td<n;td++){
                    res = max(res, ts[td][city]+dp[day-1][td]);
                }
                dp[day][city]= max(res, dp[day][city]);
            }
        }
        return *max_element(dp[k].begin(), dp[k].end());
    }
};