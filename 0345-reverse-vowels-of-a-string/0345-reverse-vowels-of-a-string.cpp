class Solution {
public:
    bool isVovel(char c)
    {
         return c=='A' or c=='E' or c=='I' or c=='O' or c=='U' or c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    string reverseVowels(string s) {
        vector<char> vow;
        string ans="";
        for(auto i:s){
            if(isVovel(i)){
                vow.push_back(i);
            }
        }

        reverse(vow.begin(),vow.end());
        int j=0;
        for(auto i:s){
            if(isVovel(i)){
            ans+=vow[j];
            j++;
        }
        else{ans+=i;}}
        return ans;
    }
};