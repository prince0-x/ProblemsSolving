class KthLargest {
    private:
    int k;
    priority_queue<int,vector<int>, greater<int>>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto i:nums)
        {
            if(pq.size()<k)
            {
                pq.push(i);
            }
            else if(i>pq.top())
            {
                pq.push(i);
                if(pq.size()>k){pq.pop();}
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<k)
        {
            pq.push(val);
        }
        else if(val>pq.top())
        {
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */