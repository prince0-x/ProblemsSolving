class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candy(n, 1);
        candy[0]=1;
        for(int i =1;i<n;i++){
            if(candy[i-1]>=candy[i] && ratings[i]>ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }
        for(int i =n-2;i>=0;i--){
            if( candy[i+1]>=candy[i]&& ratings[i]>ratings[i+1]){
                candy[i] = candy[i+1]+1;
            }
        }
        for(auto i:candy)cout<<i<<" ";
        int ans = accumulate(candy.begin(), candy.end(), 0);
        return ans;
    }
};