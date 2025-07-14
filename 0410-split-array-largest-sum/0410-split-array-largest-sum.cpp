class Solution {
public:
int cando(int mid, int k, vector<int>&nums){
    int count=0, val=0;
    for(auto i:nums){
        if(val+i<=mid){
            val+=i;
        }else{
            count++;
            val=i;
        }
    }
    return count ==k;
}
    int splitArray(vector<int>& nums, int k) {
        // return hemant(nums,k);
        int low = *max_element(nums.begin(),nums.end()),
            high = accumulate(nums.begin(),nums.end(),0),res = 0;
            while(low<=high){
                int mid = low+ (high-low)/2;
                if(cando(mid, k, nums)){
                    low=mid+1;
                }else{
                    high = mid-1;
                }
            }
        return low;
    }
    int hemant(vector<int>& nums,int k){
        const int n = nums.size();
        int s = *max_element(nums.begin(),nums.end()),
            e = accumulate(nums.begin(),nums.end(),0),res = 0;
        while(s <= e){
            int mid = s + (e - s) / 2;
            int cnt = 1,sum = 0;
            for(int i = 0; i < n; i++){
                if(sum + nums[i] <= mid) sum += nums[i];
                else{
                    sum = nums[i];
                    cnt++;
                }
            }
            if(cnt == k) res = mid,e = mid - 1;
            else s = mid + 1;
        }
        return res;
    }
};