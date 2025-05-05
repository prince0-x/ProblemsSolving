class Solution {
public:
    void solve(int index,vector<int>&temp, vector<int>candidates, int target, vector<vector<int>>&s){
      
         if(target==0){
            s.push_back(temp);
            return ;
        }
        

        

        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1])continue;
            if(candidates[i] > target)break;
            temp.push_back(candidates[i]);
            solve(i+1, temp, candidates, target-candidates[i], s);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // int sum=accumulate(candidates.begin(), candidates.end(), 0);
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>s;
        // for(auto i: candidates)cout<<i<<" ";
        // if(target>sum)return {};
        vector<int>temp;
        solve(0,temp, candidates, target,s);
        return s;
    }
};