class NumArray {
public:
    vector<int>seg;
    int n;
    void build(int ind, int low, int high, vector<int>&nums)
    {
        if(low == high)
        {
            seg[ind]=nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*ind+1, low, mid, nums);
        build(2*ind+2, mid+1, high, nums);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n);
        build(0,0, n-1, nums);  
    }
    void update1(int ind, int low, int high, int i, int val)
      {
            if(low == high)
            {
                  seg[ind]= val;
                  return;
            }
            int mid = (low+high)/2;
            if(i<=mid)update1(2*ind+1, low, mid, i, val);
            else update1(2*ind+2, mid+1, high, i, val);
            seg[ind]= seg[2*ind+1]+seg[2*ind+2];
      }
    void update(int index, int val) {
        update1(0,0,n-1,index,val);
        // nums[i]=val;
    }
    int query(int ind, int low, int high,int l, int r)
    {
        if(r<low || high<l)return 0;

        if(low>=l and high<=r) return seg[ind];

        int mid = (low+high)/2;
        int left=query(2*ind+1, low, mid, l, r);
        int right=query(2*ind+2, mid+1, high, l, r);

        return left+right;
    }
    int sumRange(int left, int right) {
        return query(0, 0, n-1, left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */