class Solution {
public:
vector<int>generaterow(int row)
{
    long long ans=1;
    vector<int >v;
    v.push_back(1);
    for(int i=1;i<row;i++)
    {
        ans=ans*(row-i);
        ans=ans/i;
        v.push_back(ans);
    }
    return v;

}

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            ans.push_back(generaterow(i+1));
        }
        return ans;
    }
};