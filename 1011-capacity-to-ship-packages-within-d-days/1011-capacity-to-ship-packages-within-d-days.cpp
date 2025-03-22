class Solution {
public:
    bool cando(vector<int>&arr, int mid, int days){
        int val =mid, ans =0;
        for(int x : arr){
            if(x<=val){
                val-=x;
            }
            else{
                ans++;
                val = mid-x;
            }
        }
        ans++;
        return ans<= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        while(low <= high){
            int mid = (low + high)/2;
            if(cando(weights, mid, days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};