class Solution {
public:
    int minimumMoves(string s) {
        int ans=0, i=0;
        while(i<s.size()){
            if(s[i] == 'X'){
                ans++;
                i+=2;
            }
            i++;
        }
        return ans;
    }
};