class Solution {
public:

    int findNumbers(vector<int>& nums) {
      int count=0;
        for(int i=0;i<nums.size();i++)
        {
          int x=nums[i];
          int c=0;
          while(x>0)
          {
            x=x/10;
            c++;
          }
          if(c%2==0)
          {
            count++;
          }
        }
        return count;
    }
};