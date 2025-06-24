class Solution {
public:
    vector<pair<int, int>>directions ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  void dfs(int i, int j,vector<vector<char>>&mat ,vector<vector<bool>>&vis){
      auto issafe =[&](int a, int b){
          return a<mat.size() && a>=0 && b<mat[0].size() && b>=0;
      };
      vis[i][j]=true;
      for(auto dir:directions){
          int newx = i+dir.first;
          int newy = j+dir.second;
          if(issafe(newx, newy) && !vis[newx][newy] && mat[newx][newy]=='O'){
              dfs(newx, newy, mat, vis);
          }
      }
  }
    
        // code here
        
    void solve(vector<vector<char>>&mat) {
        int R = mat.size();
        int C = mat[0].size();
        
        vector<vector<bool>>vis(R, vector<bool>(C, false));
       
        for(int i =0;i<R;i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i, 0, mat,vis);
            }
            if(!vis[i][C-1] && mat[i][C-1] =='O'){
                dfs(i, C-1, mat,vis);
            }
        }
        for(int i =0;i<C;i++){
            if(!vis[0][i] && mat[0][i]=='O'){
                dfs(0, i, mat,vis);
            }
            if(!vis[R-1][i] && mat[R-1][i] =='O'){
                dfs(R-1, i, mat,vis);
            }
        }
        
        
        for(int i =0;i<R;i++){
            for(int j =0; j<C;j++){
                if(vis[i][j] ){
                    mat[i][j]='O';
                }else{
                    mat[i][j]='X';
                }
            }
        }
    }
};