#define ll long long
class Solution {
public:
    int maximumRequests(int m, vector<vector<int>>& req) {
        ll n=req.size();
        ll ans=0, total=1<<n;
        for(ll mask=0; mask<total; mask++){
            ll cnt =__builtin_popcount(mask);
            if(cnt<=ans)continue;
            vector<ll>b(m, 0);
            for(int i=0;i<n;i++){
                if((mask>>i)&1){
                    b[req[i][0]]--;
                    b[req[i][1]]++;
                }
            }
            bool ok =1;
            for(int i=0;i<m;i++){
                if(b[i]){
                    ok=0;
                    break;
                }
            }
            if(ok)ans=cnt;
        }
        return ans;
    }
};