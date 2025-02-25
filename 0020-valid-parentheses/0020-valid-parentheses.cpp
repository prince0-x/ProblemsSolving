class Solution {
public:
bool isMatching(char a, char b)
    {
        return (a=='(' && b==')' )|| (a=='{' && b =='}') || (a=='[' && b==']');
    }
    bool isValid(string t) {
        stack<char>s;
        for(auto i:t)
        {
            if(i == '(')
            {
                s.push(i);
            }
            else{
                if(!s.empty() and isMatching(s.top(),i) )
                {
                    s.pop();
                }
                else{
                    s.push(i);
                }
            }
        }
        return s.empty();
    }
};