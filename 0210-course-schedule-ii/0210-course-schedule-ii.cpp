class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int>indegree(numCourses, 0), ans;
        for (auto i : prerequisites) {
            g[i[1]].push_back(i[0]); 
            indegree[i[0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        
        int count = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto nbr:g[f]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        return ans;
    }
};