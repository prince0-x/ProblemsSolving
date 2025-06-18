class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>s=score;
        unordered_map<int, string>m;
        sort(s.rbegin(), s.rend());
        int rank =1;
        for(auto i: s){
            if(m.size()<1){
                m[i]="Gold Medal";
                rank++;
            }else if(m.size()<2){
                m[i]="Silver Medal";
                rank++;
            }else if(m.size()<3){
                m[i]="Bronze Medal";
                rank++;
            }else{
                m[i] = to_string(rank);
                rank++;
            }
        }
        vector<string>ans;
        for(auto i: score){
            ans.push_back(m[i]);
        }
        return ans;
    }
};