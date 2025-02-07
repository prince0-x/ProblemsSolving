class Solution {
public:
    void helper(string output, int open, int close, int ind, int n, vector<string>&ans)
    {
        if(ind==2*n)
        {
            ans.push_back(output);
            return;
        }
        if(open<n)
        {
            helper(output+'(', open+1, close, ind+1, n, ans);
        }
        if(close<open)
        {
            helper(output+")", open, close+1, ind+1, n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n==0)return ans;
        string s="";
        helper(s, 0, 0, 0, n, ans);
        return ans;
    }
};