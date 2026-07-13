class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>small, large;
        for(int i=1; i*i<=n; i++){
            if(n%i==0){
                small.push_back(i);
                if(i!=n/i){
                    large.push_back(n/i);
                }
            }
        }
        reverse(large.begin(), large.end());
        for(auto l:large)small.push_back(l);
        return k>small.size()?-1:small[k-1];
    }
};