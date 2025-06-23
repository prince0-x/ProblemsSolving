class Solution {
public:
    bool dfs(vector<vector<int>>&g,int node,vector<bool>&vis,vector<bool> &recStack)
    {
        vis[node] = true;
    recStack[node] = true;

    for (auto i : g[node]) {
        if (!vis[i]) {
            if (dfs(g, i, vis, recStack)) {
                return true;
            }
        } else if (recStack[i]) {
            return true;
        }
    }

    recStack[node] = false; 
    return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> g(numCourses);
    for (auto i : prerequisites) {
        g[i[1]].push_back(i[0]); 
    }

    vector<bool> vis(numCourses, false);
    vector<bool> recStack(numCourses, false); 

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (dfs(g, i, vis, recStack)) {
                return false; 
            }
        }
    }

    return true;
    }
};