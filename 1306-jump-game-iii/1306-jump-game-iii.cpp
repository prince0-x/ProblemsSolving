class Solution {
public:
    
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        q.push(start);
        vector<bool>vis(n,false);
        vis[start] = true;

        while(!q.empty()){
            int siz= q.size();
            for(int i =0;i<siz;i++){
                int f = q.front();
                q.pop();
                if(arr[f]== 0)return true;
                if(f+arr[f] <n && !vis[f+arr[f]] ){
                    q.push(f+arr[f]);
                    vis[f+arr[f]]=true;
                }
                if(f-arr[f] >=0 && !vis[f-arr[f]] ){
                    q.push(f-arr[f]);
                    vis[f-arr[f]] = true;
                }
            }
        }
        return false;
    }
};