class SegmentTree {
    vector<int> tree;
    int size;

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0); // Safe size for segment tree
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node]++;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx);
        else
            update(2 * node + 1, mid + 1, r, idx);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) +
               query(2 * node + 1, mid + 1, r, ql, qr);
    }
};
class Solution {
public:
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> compressed;

    int idx = 0;
    for (int num : sorted) {
        if (compressed.find(num) == compressed.end())
            compressed[num] = idx++;
    }

    SegmentTree seg(idx);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int mapped = compressed[nums[i]];
        ans[i] = seg.query(1, 0, idx - 1, 0, mapped - 1);
        seg.update(1, 0, idx - 1, mapped);
    }

    return ans;
}


   
};