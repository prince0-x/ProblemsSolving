class Solution {
public:
    void perm(int start,int k, int end, vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return ;
        }
        for(int num =start; num<=end; num++){
            temp.push_back(num);
            perm(num+1, k,end,temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        perm(1, k, n, temp, ans);
        return ans;
    }
};