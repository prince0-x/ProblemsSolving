class Solution {
public:
    int ladderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        set<string>s(wordList.begin(), wordList.end()), vis;
        queue<string>q;
        q.push(startWord);
        vis.insert(startWord);
        int ans =0;
        while(!q.empty()){
            ans++;
            int siz = q.size();
            for(int i =0; i<siz; i++){
                string word = q.front();
                if(word ==targetWord)return ans;
                q.pop();
                for(int i=0;i<word.size();i++){
                    string temp = word;
                    for(char j ='a'; j<='z'; j++)
                    {
                        temp[i]=j;
                        if(s.find(temp)!=s.end() && !(vis.find(temp)!=vis.end()))
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};