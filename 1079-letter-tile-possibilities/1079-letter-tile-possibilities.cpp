class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<int>freq(26,0);
        vector<int>fact(n+1,1);
        for(auto c : tiles)
        {
            freq[c-'A']++;
        }
        for(int i=1;i<=n;i++)
        {
            fact[i]=i*fact[i-1];
        }
        vector<int> lengthCount(n+1,0);
        lengthCount[0]=1;
        for(int i =0; i<26;i++)
        {
            if(freq[i]>0)
            {
                vector<int>temp(n+1,0);
                for(int j=0;j<=n and lengthCount[j]>0 ; j++)
                {
                    for(int k=1;k<=freq[i];k++)
                    {
                        int totalLength = j+k;
                        temp[totalLength]+=lengthCount[j]*fact[totalLength]/(fact[k]*fact[j]);
                    }
                }
                for(int j=0;j<=n;j++)
                {
                    lengthCount[j]+=temp[j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += lengthCount[i];
        }
        return ans;
    }
};