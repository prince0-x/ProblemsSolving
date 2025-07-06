class Solution {
public:
    int ladderLength(string startWord, string endWord, vector<string>& wordList) {
        unordered_set<string>vis, s(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                auto f = q.front();
                
                string word = f.first;
                int step = f.second;
                if(word==endWord){
                    return step;
                }
                q.pop();
                
                for(int j=0;j<word.size();j++){
                    string temp = word;
                    for(char ch='a';ch<='z';ch++){
                        temp[j]=ch;
                        if(vis.find(temp)==vis.end()&& s.find(temp)!=s.end()){
                            vis.insert(temp);
                            q.push({temp, step+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};