class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>vis(n*n+1,0);
        int ans1,ans2;
        for(auto i:grid)
        {
            for(auto j :i)
            {
                vis[j]++;
            }
        }
       for(int i=1;i<=n*n;i++)
       {
        if(vis[i]==0)
        {
            ans1=i;
        }
        if(vis[i]==2)
        {
            ans2= i;
        }
       }
       return {ans2,ans1};
    }
};