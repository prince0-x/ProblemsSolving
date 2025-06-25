class Solution {
public:
    double dfs(string src, string dest, double val,unordered_set<string>&vis,map<string, vector<pair<double, string>>>&g ){
        vis.insert(src);
        if(src==dest)return val;
        for(auto [k, v]:g[src]){
             if(!(vis.find(v)!=vis.end())){
                double ans= dfs(v, dest, val*k, vis, g);
                if(ans!=-1.0)return ans;
             }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<double, string>>>g;
        for(int i = 0; i < equations.size(); i++){
            g[equations[i][0]].push_back({values[i], equations[i][1]});
            g[equations[i][1]].push_back({1.0/values[i], equations[i][0]});
        }

        
        vector<double>ans;
        for(int i =0; i<queries.size();i++){
            if(!(g.find(queries[i][0])!=g.end()) ||!(g.find(queries[i][0])!=g.end())  )ans.push_back(-1.0);
            else{
                double val =1.0;
                unordered_set<string>vis;
                ans.push_back(dfs(queries[i][0], queries[i][1], val,vis, g));
            }
        }
        return ans;
    }
};