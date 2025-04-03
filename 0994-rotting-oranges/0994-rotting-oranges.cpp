class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pair<int, int>>rotted;
        vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i =0;i<mat.size();i++){
            for(int j =0;j<mat[0].size(); j++){
                if(mat[i][j]==2){
                    rotted.push({i, j});
                }
            }
        }
        int time = (rotted.size()>0?-1:0);
        while(!rotted.empty()){
            time++;
            int size = rotted.size();
            for(int i=0; i<size;i++){
                int x = rotted.front().first;
                int y = rotted.front().second;
                rotted.pop();
                for(auto dir:directions){
                    int newx = x+dir.first;
                    int newy = y+dir.second;
                    if(newx>=0 && newx<mat.size() && newy>=0 && newy<mat[0].size() && mat[newx][newy]==1)
                    {
                        rotted.push({newx, newy});
                        mat[newx][newy]=2;
                    }
                }
            }
        }
        for(int i =0;i<mat.size();i++){
            for(int j =0;j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};