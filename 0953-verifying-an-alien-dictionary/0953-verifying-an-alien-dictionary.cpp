class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words){
             for (char &c : w){
                c =char(mapping[c - 'a']);
                cout<<c<<" ";
            }
            cout<<"\n";
        }
           
                
        return is_sorted(words.begin(), words.end());
    }
};