class Solution {
public:
void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(c, t, 0, curr, res);
        return res;
    }
};