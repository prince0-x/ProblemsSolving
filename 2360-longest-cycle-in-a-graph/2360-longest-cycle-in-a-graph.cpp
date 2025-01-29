class Solution {
public:
    int maxlen=-1;
    void dfs(vector<int>& edges,vector<int>&prevind,vector<int>&vis, int curr, int currindex)
    {
        if(prevind[curr])
        {
            maxlen=max(maxlen, currindex-prevind[curr]);
            return ;
        }
        if(!vis[curr])
        {
            prevind[curr]=currindex;
            currindex++;
            vis[curr]=1;
            if(edges[curr]!=-1)
            {
                dfs(edges, prevind, vis, edges[curr], currindex);
            }
        }
        prevind[curr]=0;
        return;
    }
    int longestCycle(vector<int>& edges) {
        vector<int>vis(edges.size(),0), prevind(edges.size(),0);
        maxlen=-1;
        for(int i=0;i<edges.size();i++)
        {
            if(!vis[i]) dfs(edges, prevind, vis, i, 1);
        }
        return maxlen;
    }
};