class Solution {
public:
    int balancedStringSplit(string s) {
        int val=0, ans=0;
        for(int i =0; i<s.size(); i++){
            if(s[i] == 'L')val++;
            else val--;
            if(val ==0)ans++;
        }
        return ans;
    }
};