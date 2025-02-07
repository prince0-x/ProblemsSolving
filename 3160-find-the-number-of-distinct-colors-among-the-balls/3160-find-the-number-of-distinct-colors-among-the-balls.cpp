class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& query) {
        int n = query.size();
        vector<int>ans(n);
        
        unordered_map<int,int>m,col;
        int i=0;
        for(auto q:query)
        {
            int ball=q[0], clr = q[1];

            if(col.find(ball)!=col.end())
            {
                int prev = col[ball];
                m[prev]--;
                if(m[prev]==0)m.erase(prev);
            }
            col[ball]=clr;
            m[clr]++;
            ans[i]=m.size();
            i++;
        }
        return ans;
    }
};