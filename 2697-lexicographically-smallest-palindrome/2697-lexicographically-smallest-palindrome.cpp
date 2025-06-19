class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        for(int i=0;i<n/2;i++){
            int v1= int(s[i]-'a');
            int v2 = int(s[n-i-1]-'a');
            v1=min(v1, v2);
            s[i]=s[n-i-1]=char('a'+v1);
        }
        return s;
    }
};