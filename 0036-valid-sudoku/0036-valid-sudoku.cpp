class Solution {
public:
   
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>rows[9], cols[9], subBox[9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char c = board[i][j];
                if(c!='.')
                {
                    if(cols[j].count(c) || rows[i].count(c) or subBox[(i/3)*3+j/3].count(c))return false;

                    rows[i].insert(c);
                    cols[j].insert(c);
                    subBox[(i / 3) * 3 + (j / 3)].insert(c);
                }
            }
        }
        return true;
    }
};