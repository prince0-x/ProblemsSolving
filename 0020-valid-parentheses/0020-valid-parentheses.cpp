class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(isOpening(c))
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                {
                    return false;
                }
                else if(!isMatching(st.top(),c))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    bool isOpening(char c)
    {
        return c=='(' || c=='{' || c=='[';
    }
    bool isMatching(char a, char b)
    {
        return (a=='(' && b==')' )|| (a=='{' && b =='}') || (a=='[' && b==']');
    }
};