class Solution {
public:
const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        if(s.size()==0)return 0;
        vector<int>ind(26,-1),dp(n, 0);

        ind[s[0]-'a']=0;
        dp[0]=1;

        for(int i =1;i<n;i++){
            if(ind[s[i]-'a'] == -1){
                dp[i]=(0LL+dp[i-1]*2+1)%MOD; 
            }
            else{
                int val = ind[s[i]-'a']; 
                int temp =(val==0)?1: dp[val-1]+1;
                dp[i]= (0LL+2*dp[i-1]+1-temp+MOD )%MOD;
                
            }
            ind[s[i]-'a']=i; 
        }
        return dp[n-1];
    }
};