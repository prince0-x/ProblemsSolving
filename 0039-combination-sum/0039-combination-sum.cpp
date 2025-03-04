class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    void solve(vector<int>&c, int index, int target)
    {
         if(target==0)
            {
                res.push_back(curr);
                return;
            }
        if(target<0)return;
        if(index==c.size())
        {
            return;
        }
        curr.push_back(c[index]);
        solve(c,index, target-c[index]);
        curr.pop_back();
        solve(c,index+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        solve(c,0,t);
        return res;
    }
};