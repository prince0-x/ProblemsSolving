class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int , vector<int>, greater<int>>pq(nums.begin(),nums.end());
        long long  mod = 1e9+7;
        for(int i=0;i<k;i++)
        {
            int val =pq.top()+1;
            pq.pop();
            pq.push(val);
        }
        int ans = 1;
        while(!pq.empty())
        {
            ans = (1LL*ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};