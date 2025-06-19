class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = count(s.begin(), s.end(), '1')-1;
        string ans(s.size(), '0');
        ans[s.size()-1]='1';
        for(int i=0;i<ans.size()-1;i++){
            if(one > 0){
                ans[i] = '1';
                one--;
            }else{
                break;
            }
        }
        return ans;
    }
};