
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& e) {
        if(n==1 and e.size()==0)return 1;
      vector<int>v(n+1);
      for(auto i:e)
      {
         v[i[0]]--;
         v[i[1]]++;
      }
      for(int i=0;i<=n;i++)
      {
        if(v[i]==n-1)return i;
      }
      return -1;
    }
};