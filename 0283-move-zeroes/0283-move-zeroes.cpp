class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>arr;
        for(auto i:nums)
        {
            if(i!=0){
                arr.push_back(i);
            }
        }
        for(auto i:nums){
            if(i==0)arr.push_back(i);
        }
        for(int i =0;i<arr.size();i++){
            nums[i]=arr[i];
        }
    }
};