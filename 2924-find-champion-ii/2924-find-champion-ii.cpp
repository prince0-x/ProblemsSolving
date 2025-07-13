class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>deg(n, 0);
        for(auto e:edges){
            deg[e[1]]++;
        }
        int ans, count=0;
        for(int i=0;i<n;i++){
            if(deg[i]==0){
                count++;
                ans=i;
            }
        }
        if(count>1) return -1;
        return ans;
    }
};