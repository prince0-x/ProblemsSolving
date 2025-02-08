class Solution {
public:
    int count_invalid (string s)
    {
        stack<char>st;
        for(int i=0;i<s.size(); i++)
        {
            if(s[i]=='(') st.push(s[i]);
            else if (s[i]==')')
            {
                if(!st.empty() and st.top() == '(')
                {
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
    void help(string s, int mini, unordered_set<string>&vis, unordered_set<string>&ans)
    {
        if(mini<0)return;
        if(vis.count(s))return;

        vis.insert(s);
        if(mini == 0)
        {
            if(count_invalid(s)==0)
            {
                ans.insert(s);
            }
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if (i > 0 && s[i] == s[i-1]) continue;
            if(s[i]=='(' || s[i]==')')
            {
                string left = s.substr(0,i);
                string right = s.substr(i+1);
                help(left+right, mini-1, vis, ans);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans, vis;
        int mini = count_invalid(s);
        help(s, mini, vis, ans);
        return vector<string>(ans.begin(), ans.end());
        
    }
};