class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i =1;i<=n;i++){
            for(int j =1; j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i =n, j=m;
        string lcs="", ans="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                lcs=str1[i-1]+lcs;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                  i--;
                }
                else {
                    j--;
                }
            }
            
        } 
        int k=0;
        i=0, j =0;
        while(k<lcs.size()){
            while(i<n && k< lcs.size() && lcs[k]!=str1[i]){
                ans+=str1[i];
                i++;
            }
            while(j<m && k< lcs.size() && lcs[k]!=str2[j]){
                ans+=str2[j];
                j++;
            }
            ans+=lcs[k];
            k++;
            i++;
            j++;
        }


        while(i<n){
            ans+=str1[i];
            i++;
        }
        while(j<m){
            ans+=str2[j];
            j++;
        }
        return ans;
    }
};