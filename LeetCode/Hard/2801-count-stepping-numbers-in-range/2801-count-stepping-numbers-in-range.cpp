class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    long long dp[101][2][2][11];

    long long solve(string &s, int n, int ind, int tight, int lz, int prev) {
        if (ind == n) {
            return !lz; // count only positive integers
        }

        if (dp[ind][tight][lz][prev] != -1) {
            return dp[ind][tight][lz][prev];
        }

        int limit = tight ? s[ind] - '0' : 9;

        long long ways = 0;

        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);
            int nlz = lz && (d == 0);

            if (nlz) {
                ways = (ways +
                        solve(s, n, ind + 1, ntight, 1, 10)) % MOD;
            } else {
                if (prev == 10 || abs(prev - d) == 1) {
                    ways = (ways +
                            solve(s, n, ind + 1, ntight, 0, d)) % MOD;
                }
            }
        }

        return dp[ind][tight][lz][prev] = ways;
    }

    string subtractOne(string s) {
        if (s == "0") return "0";

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] > '0') {
                s[i]--;
                break;
            }
            s[i] = '9';
        }

        int pos = 0;

        while (pos + 1 < (int)s.size() && s[pos] == '0') {
            pos++;
        }

        return s.substr(pos);
    }

    long long countUpTo(string s) {
        memset(dp, -1, sizeof(dp));

        int n = (int)s.size();

        return solve(s, n, 0, 1, 1, 10);
    }

    int countSteppingNumbers(string low, string high) {
        string lowMinusOne = subtractOne(low);

        long long highAns = countUpTo(high);
        long long lowAns = countUpTo(lowMinusOne);

        return (highAns - lowAns + MOD) % MOD;
    }
};