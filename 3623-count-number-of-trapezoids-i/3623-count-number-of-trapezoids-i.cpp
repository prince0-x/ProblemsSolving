#define ll long long 
class Solution {
public:
   const int mod = 1e9+7;
   unordered_map<int, int>same_y;
    int countTrapezoids(vector<vector<int>>& points) {
        for(auto&p:points){
            same_y[p[1]]++;
        }
        ll sum=0, ans=0;
        for(auto[k, v]:same_y){
            ll edge=(ll)v*(v-1)/2;
            ans+=edge*sum;
            sum+=edge;
        }
        return ans%mod;
    }
};