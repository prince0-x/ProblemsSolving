class Solution {
    private:
    static const int MAXI=1e7+1;
    static int num[MAXI];

    
public:
    void precompute(int n){
        fill(num, num + MAXI, 1);
        num[0]=num[1]=0;
        for(int i=2; i*i<=n; i++){
            if(num[i]){
                for(int j=i*i; j<=n; j+=i){
                    num[j]=0;
                }
            }  
        }
        for(int i=1; i<=n; i++){
            num[i]+=num[i-1];
        }
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        precompute(n);
        return num[n-1];
    }
};
int Solution::num[Solution::MAXI];