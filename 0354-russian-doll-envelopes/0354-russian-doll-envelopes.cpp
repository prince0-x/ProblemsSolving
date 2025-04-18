class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        sort(en.begin(), en.end(), [](vector<int>&a, vector<int>&b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        // vector<int>dp(en.size(), 1);
        // for(int i=1;i<en.size();i++){
        //     for(int j =0; j<i;j++){
        //         if(en[i][0]>en[j][0] && en[i][1]>en[j][1]){
        //             dp[i]=max(dp[i], 1+dp[j]);
        //         }
        //     }
        // }
        vector<int>ans;
       for(auto i :en){
          int ind = lower_bound(ans.begin(), ans.end(), i[1])-ans.begin();
          if(ind != ans.size())ans[ind] = i[1];
          else ans.push_back(i[1]);
       }
       return ans.size();
        // return *max_element(dp.begin(), dp.end());
    }
};