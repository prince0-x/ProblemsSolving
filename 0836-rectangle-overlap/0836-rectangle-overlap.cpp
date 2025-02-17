class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int ox1 = max(rec1[0],rec2[0]);
        int oy1 = max(rec1[1],rec2[1]);
        int ox2 = min(rec1[2],rec2[2]);
        int oy2 = min(rec1[3],rec2[3]);
        if(ox2>ox1 and oy2>oy1)return true;
        return false;
    }
};