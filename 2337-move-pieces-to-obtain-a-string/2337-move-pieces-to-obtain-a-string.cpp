class Solution {
public:
    bool canChange(string start, string target) {
        int n= start.size();
        for(int i=0,j=0; i<n or j<n; i+=1, j+=1)
        {
            while(i<n and start[i]=='_')i+=1;
            while(j<n and target[j]=='_')j+=1;
            char ch = start[i];
            if(ch != target[j])return false;
            if(ch == 'R' and i>j)return false;
            if(ch == 'L' and i<j)return false;
        }
        return true;   
    }
};