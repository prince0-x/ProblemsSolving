class Solution {
public:
    bool cando(vector<int>& arr,int mid, int threshold){
        int ans =0;
        for(auto x : arr){
            if(ans>threshold)return false;
            ans += x/mid + (x%mid!=0);
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high)
        {
            int mid = (low + high )/2;

            if(cando(nums, mid, threshold))
            {
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};