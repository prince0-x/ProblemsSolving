class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       int  n = nums.size(), count =0;
       unordered_map<int, int>m;
       for(auto i:nums){
        m[i]++;
       }
       

       for(int i =0;i<n;i+=3){
        bool f = true;
        for(auto [k,v]:m){
            if(v>1) f=false;
        }
        if(f)break;
        m[nums[i]]--;
        if(i+1<n)m[nums[i+1]]--;
        if(i+2<n)m[nums[i+2]]--;
        count+=1;
       }
       return count;
    }
    
};