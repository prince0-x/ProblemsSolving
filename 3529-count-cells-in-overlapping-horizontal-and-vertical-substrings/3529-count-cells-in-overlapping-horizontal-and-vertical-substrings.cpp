class Solution {
public:
    vector<int> getLPS(string &s, int n) {
        vector<int> LPS(n);
        for(int i = 1; i < n; i++) {
            int j = LPS[i - 1];
            while(j > 0 && s[i] != s[j]) {
                j = LPS[j - 1];
            }
            if(s[i] == s[j]) j++;
            LPS[i] = j;
        }
        
        return LPS;
    }
     
    int countCells(vector<vector<char>> &grid, string pattern) {
        int n = grid.size(), m = grid[0].size(), sz = pattern.size();
        
        string horizontalString = "";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                horizontalString += grid[i][j];
            }
        }
        
        string verticalString = "";
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                verticalString += grid[j][i];
            }
        }
        
        string horizontalPatternString = pattern + "#" + horizontalString;
        vector<int> lps1 = getLPS(horizontalPatternString, horizontalPatternString.size());
        
        string verticalPatternString = pattern + "#" + verticalString;
        vector<int> lps2 = getLPS(verticalPatternString, verticalPatternString.size());

        int sz1 = lps1.size();
        vector<int> scan1(sz1 + 1);
        for(int i = 0; i < sz1; i++) {
            if(lps1[i] == sz) {
                scan1[i - sz + 1]++;
                scan1[i + 1]--;
            }
        }
        
        int sz2 = lps2.size();
        vector<int> scan2(sz2 + 1);
        for(int i = 0; i < sz2; i++) {
            if(lps2[i] == sz) {
                scan2[i - sz + 1]++;
                scan2[i + 1]--;
            }
        }
        
        vector<vector<bool>> visited(n, vector<bool> (m));
        
        int count1 = 0;
        for(int i = 0; i < sz1; i++) {
            count1 += scan1[i];
            if(count1 > 0) {
                int idx = i - sz - 1;
                int row = idx / m, column = idx % m;
                visited[row][column] = true;
            }
        }
        
        int count2 = 0;
        int ans = 0;
        for(int i = 0; i < sz2; i++) {
            count2 += scan2[i];
            if(count2 > 0) {
                int idx = i - sz - 1;
                int row = idx % n, column = idx / n;
                if(visited[row][column]) ans++;
            }
        }
        
        return ans;
    }
};