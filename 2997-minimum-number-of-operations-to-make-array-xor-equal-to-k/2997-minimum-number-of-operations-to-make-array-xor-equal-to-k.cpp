class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       int xorA = nums[0];
       for(int i=1 ; i<nums.size();i++)
       {
        xorA^=nums[i];
       }
       int cnt=0;
       xorA^=k;
       while(xorA>0)
       {
        if(xorA&1!=0)cnt++;
       xorA= xorA>>1;
       }
      return cnt;  
    }
};