struct Node {
    int product;  // Stores the product modulo k of the segment
    int count[5];  // Array to store the count of each remainder in the segment modulo k

    // Constructor to initialize the node
    Node(int k = 0) {
        product = 1 % max(1, k);  // Initializes product to 1, modulo k
        memset(count, 0, sizeof(count));  // Initializes all count values to 0
    }
};


class Solution {
public:
    int n, k, treeSize;
    vector<Node> segmentTree;
    Node merge(const Node &L, const Node &R) const {
    Node res(k);
    res.product = int((1LL * L.product * R.product) % k);
    for (int r = 0; r < k; ++r) res.count[r] = L.count[r];
    for (int r2 = 0; r2 < k; ++r2) {
        int c = R.count[r2];
        if (c) {
            int r = int((1LL * L.product * r2) % k);
            res.count[r] += c;
        }
    }
    return res;
}

void build(const vector<int> &nums) {
    treeSize = 1;
    while (treeSize < n) treeSize = treeSize * 2;  // replaced <<= with *2
    segmentTree.assign(2 * treeSize, Node(k));

    for (int i = 0; i < n; ++i) {
        int modVal = nums[i] % k;
        Node &nd = segmentTree[treeSize + i];
        nd = Node(k);
        nd.product = modVal;
        nd.count[modVal] = 1;
    }

    int p = treeSize - 1;
    while (p > 0) {
        segmentTree[p] = merge(segmentTree[2 * p], segmentTree[2 * p + 1]);
        --p;
    }
}

void update(int index, int newModValue) {
    int pos = treeSize + index;
    segmentTree[pos] = Node(k);
    segmentTree[pos].product = newModValue;
    segmentTree[pos].count[newModValue] = 1;

    while (pos > 0) {
        pos = pos / 2;  // move to the parent node
        segmentTree[pos] = merge(segmentTree[2 * pos], segmentTree[2 * pos + 1]);
    }
}

Node query(int left, int right) const {
    Node leftResult(k), rightResult(k);
    left += treeSize;
    right += treeSize;

    while (left <= right) {
        if (left % 2 == 1) {
            leftResult = merge(leftResult, segmentTree[left]);
            ++left;
        }
        if (right % 2 == 0) {
            rightResult = merge(segmentTree[right], rightResult);
            --right;
        }
        left = left / 2;
        right = right / 2;
    }
    return merge(leftResult, rightResult);
}

vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
    n = nums.size();
    k = kk;
    build(nums);
    int q = queries.size();
    vector<int> ans(q);

    for (int i = 0; i < q; ++i) {
        update(queries[i][0], queries[i][1] % k);
        Node nd = query(queries[i][2], n - 1);
        ans[i] = nd.count[queries[i][3]];
    }

    return ans;
}

};