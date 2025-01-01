class Solution {
public:
    int maxScore(string s) {
        int one=0, zero=0,ans=0;
        for(auto i:s)
        {
            one+=(i=='1'?1:0);
        }
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='0')
            {
                  zero++;
                  ans=max(ans,zero+one);
            }else
            {
                one--;
                ans=max(ans,zero+one);
            }
        }
        return ans;
    }
};