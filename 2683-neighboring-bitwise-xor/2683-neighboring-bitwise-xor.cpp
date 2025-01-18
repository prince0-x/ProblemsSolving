class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        vector<int>ans={0};
        int n = derived.size();
        for(int i=0; i<n; i++)
        {
            ans.push_back(derived[i]^ans[i]);
        }
        bool zero = (ans[0]==ans[ans.size()-1]);
        ans={0};
        for(int i=0; i<n; i++)
        {
            ans.push_back(derived[i]^ans[i]);
        }
        bool one = (ans[0]==ans[ans.size()-1]);
        return one|zero;
        
    }
};