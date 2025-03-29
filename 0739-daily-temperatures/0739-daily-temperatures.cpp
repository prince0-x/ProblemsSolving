class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        stack<pair<int, int>>s;

        for(int i =n-1;i>=0;i--){
            while(!s.empty() and s.top().second <= temp[i])
            {
                s.pop();
            }
            if(!s.empty())ans[i]=s.top().first-i;
            s.push({i, temp[i]});
        }
        return ans;
    }
};