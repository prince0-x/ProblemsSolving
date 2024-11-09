class Solution {
public:
    bool isVovel(char c)
    {
         return c=='A' or c=='E' or c=='I' or c=='O' or c=='U' or c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    string reverseVowels(string s) {
       int i=0,j=s.size()-1;
        string ans=s;
       while(i<=j)
       {
        if(isVovel(ans[i]) and isVovel(ans[j]))
        {
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
        else if(isVovel(ans[i]) and !isVovel(ans[j]))
        {
            j--;
        }
        else{
            i++;
        }
       }
        return ans;
    }
};