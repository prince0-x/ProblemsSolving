class Solution {
public:
    string largestOddNumber(string num) {
        string temp="", ans="";
        for(auto i:num)
        {
            if(int(i-'0')%2!=0)
            {
                if(temp.size()>0)
                {
                    ans+=temp;
                    temp ="";
                }
                ans+=i;
            }else{
                temp+=i;
            }
        }
        return ans;
    }
};