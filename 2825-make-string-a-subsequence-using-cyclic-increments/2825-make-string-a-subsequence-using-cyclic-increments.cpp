class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int t=0;
        int n=str2.size();
        for(char c : str1)
        {
            if(t<n && (str2[t]-c+26)%26<=1)
            {
                t++;
            }
        }
        return t==n;
    }
};