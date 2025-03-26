
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]!= x)return find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y)
    {
        int findX = find(x);
        int findY = find(y);
        if(findX != findY){
            if(rank[x] > rank[findY]){
                parent[findX] =  findY;
            }
            else if(rank[findX] < rank[findY]){
                parent[findY] = findX;
            }else{
                parent[findY] = findX;
                rank[findX]++;
            }
        }
    }
    bool isCycle(int x, int y)
    {
        return find(x)==find(y);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n = edges.size();
    //  vector<vector<int>> graph(n+1, vector<int>(n+1,0));
     parent.resize(n+1);
     for(int i =0;i<n+1;i++)parent[i]=i;
     rank.resize(n+1, 1);
     for(auto &arr: edges)
     {
        if(isCycle(arr[0],arr[1]))return {arr[0],arr[1]};
        _union(arr[0],arr[1]);
     }
     return {};
    }
};