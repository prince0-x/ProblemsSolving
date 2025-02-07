class Solution {
public:
// string print_lcs(string &s)
// {
//     if(s.size()<=1)return s;
//     int m = s.size();
//     vector<vector<int>>dp(m, vector<int>(m, 0));

//     int ans =1, lastIndex=0, initindex=0;

//     for(int i=0; i<m;i++)
//     {
//         for(int j=0; j<i;j++)
//         {
//                 if(s[i]==s[j]  and (i-j <= 2 or dp[j+1][i-1]))
//                 {
//                     dp[j][i]=1;
//                     if(i-j+1 > ans)
//                     {
//                         ans= i-j+1;
//                         lastIndex = i;
//                         initindex = j;
//                     }
//                 }
//         }
//     }
//     return s.substr(initindex,lastIndex-initindex+1);  
// }
    string longestPalindrome(string t) {
         if (t.size() <= 1) return t;

    // Transform string: Insert '#' between characters
    string s = "#";
    for (char c : t) s += c + string("#");

    int n = s.size();
    vector<int> dp(n, 0);

    int center = 0, right = 0, maxsize = 0, startIdx = 0;

    for (int i = 0; i < n; i++) {
        // If within a known palindrome boundary
        if (i < right) 
            dp[i] = min(right - i, dp[2 * center - i]);

        // Expand around the current center i
        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && s[i - dp[i] - 1] == s[i + dp[i] + 1]) 
            dp[i]++;

        // Update center and right boundary
        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }

        // Track longest palindrome
        if (dp[i] > maxsize) {
            maxsize = dp[i];
            startIdx = (i - dp[i]) / 2; // Convert index to original string
        }
    }

    return t.substr(startIdx, maxsize);
    }
};