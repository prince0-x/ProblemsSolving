#define ll long long
class Solution {
public:
    
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end());
        
        ll count=0, left=0, ans =0, n=nums.size();

        for(int right = 0; right<nums.size();right++){
           if(nums[right] == max_ele)++count;
           while(count >=k ){
            ans+=n-right;
            if(nums[left]== max_ele){
                --count;
            }
            left++;
           }
            
        }
        return ans;
    }
};