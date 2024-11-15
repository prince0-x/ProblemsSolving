class Solution {
public:
    bool isSafe(vector<string>&board,int n,int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=n or board[i][j]=='Q')
        {
            return false;
        }
        // left 
         // Check column
    for (int x = 0; x < i; x++) {
        if (board[x][j] == 'Q') {
            return false;
        }
    }

    // Check upper left diagonal
    for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == 'Q') {
            return false;
        }
    }

    // Check upper right diagonal
    for (int x = i, y = j; x >= 0 && y < n; x--, y++) {
        if (board[x][y] == 'Q') {
            return false;
        }
    }

    return true;
    }
    void solveQueen(int n, vector<vector<string>>&ans,vector<string>&board,int row)
    {
        if(row==n)
        {
            ans.push_back(board);
            return ;
        }
        
            for(int j=0;j<n;j++)
            {
                if(isSafe(board,n,row,j))
                {
                    board[row][j]='Q';
                    solveQueen(n,ans,board,row +1);
                    board[row][j]='.';
                }
            }
        

    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        vector<vector<string>>ans;
        solveQueen(n,ans,board,0);
        return ans;
    }
};