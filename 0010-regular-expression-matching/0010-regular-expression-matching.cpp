class Solution {
public:
    bool regular_expression(int i, int j, int m, int n, string &text, string &pattern, vector<vector<int>> &dp) {
        if (dp[i][j] != -1) return dp[i][j];

        if (i == n) return dp[i][j] = (j == m);

        bool curr_match = (j < m && (pattern[i] == text[j] || pattern[i] == '.'));

        if (i + 1 < n && pattern[i + 1] == '*') {
            return dp[i][j] = regular_expression(i + 2, j, m, n, text, pattern, dp) ||
                              (curr_match && regular_expression(i, j + 1, m, n, text, pattern, dp));
        }

        if (curr_match) {
            return dp[i][j] = regular_expression(i + 1, j + 1, m, n, text, pattern, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.length(), m = s.length(); // n for pattern, m for text
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return regular_expression(0, 0, m, n, s, p, dp);
    }
};
