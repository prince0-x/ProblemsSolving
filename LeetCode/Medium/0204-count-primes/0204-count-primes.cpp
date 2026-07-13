class Solution {

    
public:
    
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<bool>num(n+1,true);
        num[0]=num[1]=0;
        for(int i=2; i*i<=n; i++){
            if(num[i]){
                for(int j=i*i; j<=n; j+=i){
                    num[j]=0;
                }
            }  
        }
        int ans=0;
        for(int i=2; i<n; i++){
            ans+=num[i];
        }
        return ans;
    }
};