#define ll long long
#define vvll vector<vector<ll>>
#define vll vector<ll>
class Solution {
public:
    vvll dp;
    vll pref;
    const ll mini=LLONG_MAX;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        dp.assign(m+1, vll(n+1, mini));
        pref.assign(n+1, 0);
        for(int i=0; i<n; i++){
            pref[i+1] = pref[i]+nums[i];
        }
        for(int i=0; i<=n; i++){
            dp[0][i]=0;
        }
        ll ans = LLONG_MIN;
        for(int k=1; k<=m; k++){
            dp[k][n]=0;
            deque<int>dq;
            for(int i=n-1; i>=0; i--){
                if(i+l<=n){
                    ll curr = pref[i+l]+ dp[k-1][i+l];
                    while(!dq.empty()){
                        int b = dq.back();
                        ll val = pref[b]+dp[k-1][b];
                        if(val>=curr)break;
                        dq.pop_back();
                    }
                    dq.push_back(i+l);
                }
                while(!dq.empty() && dq.front() > i+r){
                    dq.pop_front();
                }
                dp[k][i]= dp[k][i+1];
                if(!dq.empty()){
                    int j = dq.front();
                    dp[k][i]= max(dp[k][i], dp[k-1][j]+ pref[j]-pref[i]);
                }
            }
            ans= max(ans, dp[k][0]);
            if(ans==0){
                ll b = LLONG_MIN;
                for(int i=0; i<n; i++){
                    for(int len = l; len<=r && i+len <=n; len++){
                        b=max(b, pref[i+len]-pref[i]);
                    }
                }
                return b;
            }
        }
        return ans;
    }
};