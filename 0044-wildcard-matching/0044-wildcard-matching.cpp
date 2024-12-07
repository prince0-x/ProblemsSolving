class Solution {
public:
    string s,p;
    vector<vector<int>>memo;
    bool dp(int i,int j)
    {  
        // base case
        if(i==s.size() && j==p.size())return 1;

        if (j==p.size())return 0;
        // memo 
        if(memo[i][j]!=-1)return memo[i][j];
        bool ans=false;
        // if match
        if(i<s.size() and s[i]==p[j])
        {
            ans|=dp(i+1,j+1);
        }
        // if ? occur
        else if(p[j]=='?')
        {
            if(i==s.size())return false;
            else ans|=dp(i+1,j+1);
        }
        // if * occur
        else if(p[j]=='*')
        {
            if(i<s.size())
            {
                ans|=dp(i+1,j);
            }
             ans|=dp(i,j+1);
        }
        return memo[i][j]= ans;
    }
    bool isMatch(string ss, string pp) {
        this->s=ss;
        this->p=pp;
        memo.resize(ss.size()+1,vector<int>(pp.size()+1,-1));
        return dp(0,0);
    }
};