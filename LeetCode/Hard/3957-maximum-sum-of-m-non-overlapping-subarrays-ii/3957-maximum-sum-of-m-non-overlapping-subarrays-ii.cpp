#define ll long long
class Solution {
public:
pair<ll, int>calc(ll C, int n, int l, int r, const vector<ll>&p){
    vector<ll>dp(n+1, 0);
    vector<int>cnt(n+1, 0);
    deque<int>dq;
    auto get_val=[&](int a){
        return make_pair(dp[a]-p[a], cnt[a]);
    };
    for(int i=1; i<=n; i++){
        dp[i]= dp[i-1];
        cnt[i]=cnt[i-1];
        int a =i-l;
        if(a>=0){
            while(!dq.empty()&& get_val(dq.back())<=get_val(a)){
                dq.pop_back();
            }
            dq.push_back(a);
        }
        while(!dq.empty() && dq.front() < i - r){
            dq.pop_front();
        }
        if(!dq.empty()){
            int f= dq.front();
            ll cand_val = p[i]+dp[f]-p[f]-C;
            int cand_cnt = cnt[f]+1;
            if(cand_val>dp[i]|| (cand_val==dp[i] && cand_cnt>cnt[i])){
                dp[i]=cand_val;
                cnt[i]=cand_cnt;
            }
        }
    }
    return {dp[n], cnt[n]};
}
    ll solve_for_k(int K, int n, int l, int r, const vector<ll>&p){
        ll low = -1e11, high = 1e11, ans=-2e18;
        while(low<=high){
            ll mid = low +(high- low)/2;
            auto res = calc(mid, n, l, r, p);
            if(res.second >=K){
                ans=res.first+K *mid;
                low= mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        if(n<l) return 0;
        vector<ll>p(n+1, 0);
        for(int i=0; i<n; i++){
            p[i+1]=p[i]+nums[i];
        }
        auto res0=calc(0, n, l, r, p);
        if(res0.second >m){
            return solve_for_k(m, n, l, r, p);
        }else if(res0.second >= 1){
            return res0.first;
        }
        return solve_for_k(1, n, l, r, p);
    }
};