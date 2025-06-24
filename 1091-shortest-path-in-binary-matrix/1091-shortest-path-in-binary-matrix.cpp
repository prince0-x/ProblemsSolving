class Solution {
public:
    vector<pair<int, int>>directions={{1, 1}, {1, -1}, {-1,1},{-1,-1},{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>>vis(R, vector<int>(C,0));

        auto issafe = [&](int a, int b){
            return a>=0 && a<R && b>=0 && b<C;
        };

        queue<tuple<int, int, int>>q;
        q.push({0,0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto [x,y,d] = q.front();
            q.pop();

            if(x==R-1 && y==C-1){
                    return d+1;
            }

            for(auto dir:directions){
                int newx=x+dir.first;
                int newy= y+dir.second;
                if(issafe(newx, newy) && !vis[newx][newy] && grid[newx][newy]==0)
                {
                    vis[newx][newy]=1;
                    q.push({newx, newy, d+1});
                }
                
            }
        }

        return -1;
    }
};