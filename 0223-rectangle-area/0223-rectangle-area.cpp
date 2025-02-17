class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ans = abs(ay2-ay1)*abs(ax2-ax1) + abs(by2-by1)*abs(bx2-bx1);
        ans-=(max(ax2-bx1, 0)*max(by2-ay1, 0));
        return ans;
    }
};