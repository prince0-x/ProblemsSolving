class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>sieve(n+1, 1);
        vector<int>primes;
        sieve[0]=sieve[1]=0;
        for(int i=2; i*i<=n; i++){
            if(sieve[i]){ 
                for(int j=i*i; j<=n; j+=i){
                    sieve[j]=0;
                }
            }
        }
        for(int i=0; i<=n; i++)if(sieve[i])primes.push_back(i);

        vector<vector<int>> ans;
        for (int p : primes) {
            if (p > n / 2) break;
            if (sieve[n - p]) {
                ans.push_back({p, n - p});
            }
        }
        return ans;
        
    }
};