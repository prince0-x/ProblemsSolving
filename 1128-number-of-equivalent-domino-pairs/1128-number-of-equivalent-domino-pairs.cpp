class Solution {
public:
    
    
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans=0;
        reverse(dominoes.begin(), dominoes.end());
        map<vector<int>, int>mp;
        for(auto dom: dominoes){
            vector<int>x=dom;
            sort(x.begin(), x.end());
            if(mp.find(x)!=mp.end()){
                ans+=mp[x];
            }
            mp[x]++;
        }
        return ans;
    }
};