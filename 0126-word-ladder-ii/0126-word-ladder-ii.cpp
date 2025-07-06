class Solution {
public:unordered_map<string, int>mp;
       vector<vector<string>>ans;
       string b;
       void dfs(string word, vector<string>&seq){
        if(word==b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for(int j=0;j<word.size();j++){
            char original=word[j];
            for(char ch='a';ch<='z';ch++){
                word[j]=ch;
                if(mp.find(word)!=mp.end() && mp[word]+1==steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[j]=original;
        }

       }
       
    vector<vector<string>> findLadders(string startWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<string>q;
        b=startWord;
        mp[startWord]=1;
        q.push(startWord);
        st.erase(startWord);
        int sz = startWord.size();
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word==endWord)break;
            int step = mp[word];
            for(int j=0;j<sz;j++){
                char original=word[j];
                for(char ch='a';ch<='z';ch++){
                    word[j]=ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mp[word]=step+1;
                    }
                }
                word[j]=original;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};
