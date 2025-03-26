class Solution {
public:
vector<pair<int,int>>direction={{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool dfs(int row, int col, vector<vector<char>>&board, string &word, int index, int n, int m,vector<vector<bool>>&vis)
    {
        if(index == word.size())return true;
        if(row<0 || row>=n || col<0 || col>=m || vis[row][col] ||board[row][col]!=word[index]){
                return false;
            }
        vis[row][col]=true;
        for(auto dir: direction){
            int x = dir.first+row;
            int y = dir.second+col;
          
            if(dfs(x, y, board, word, index+1, n, m, vis)){
                return true;
            }

        }
        vis[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int  n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++)
            {
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board, word, 0,n,m, vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};