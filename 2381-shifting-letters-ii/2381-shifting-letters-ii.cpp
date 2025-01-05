class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.size(),shift_val=0;
        vector<int>prefix(n,0);
        string result(n,' ');
        for(auto shift:shifts)
        {
            if(shift[2]==1)
            {
                prefix[shift[0]]++;
                if(shift[1]+1<n)
                {
                    prefix[shift[1]+1]--;
                }
            }else {
                prefix[shift[0]]--;
                if(shift[1]+1<n)
                {
                    prefix[shift[1]+1]++;
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            shift_val=(shift_val+prefix[i])%26;
            if(shift_val<0)
            {
                shift_val=(shift_val+26);
            }
            result[i]='a'+(s[i]-'a'+shift_val)%26;
        }
        return result;
    }
};