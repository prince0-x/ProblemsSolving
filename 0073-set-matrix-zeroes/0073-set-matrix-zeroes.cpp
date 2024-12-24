class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<pair<int,int>>z;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    z.push_back({i,j});
                }
            }
        }
        for(auto i:z)
        {
            for(int k=0;k<n;k++)
            {
                mat[k][i.second]=0;
            }
            for(int k=0;k<m;k++)
            {
                mat[i.first][k]=0;
            }
        }
    }
};