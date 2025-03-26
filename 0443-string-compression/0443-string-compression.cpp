class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>ans;
        int n  = chars.size();
        int i =0;
        for(int j =1;j<n;j++){
            if(chars[j]==chars[j-1])continue;
            else{
                ans.push_back(chars[i]);
                string s = to_string(int(j-i));
                if(j-i > 1){
                    for(auto k:s){
                       ans.push_back(k);
                    }
                }
                i=j;
            }
        }

        ans.push_back(chars[i]);
        if(chars[n-1]==chars[i])
        {
            string s = to_string(int(n-i));
           
            if(n-i > 1){
                    for(auto k:s){
                       ans.push_back(k);
                    }
            }
        }
        for(int i =0;i<ans.size();i++){
            chars[i]= ans[i];
        }
        return ans.size();
    }
};