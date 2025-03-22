class Solution {
public:
    bool cando(vector<int>&arr, int mid, int m, int k)
    {
        int ans = 0, current = 0;
        for(auto x: arr){
            if(x <= mid)
            {
                current++;
                if(current==k){
                    ans++;
                    current =0;
                }
            }else{
                current = 0;
            }
        }

        return ans >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size())return -1;
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){ 
            int mid = int((long long)low + (long long)high)/2;
            if(cando(bloomDay, mid, m, k)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};