class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      
        priority_queue<int>pq;
        for(auto i:nums)
        {
                 pq.push(i);
            
        }
        for(int i=0;i<k-1;i++)
        {
            pq.pop();
        }
        return pq.top();
    }
};
const static int __ = []()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                  
    cout.tie(nullptr);               
    return 0;
}();
