class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(boxes.size(),0);
        int left_ball=0, right_ball=0;
        int left_move=0, right_move=0;
        for( int i=0;i<n;i++)
        {
            ans[i]+=left_move;
            left_ball+=boxes[i]-'0';
            left_move+=left_ball;

            int index = n-i-1;

            ans[index]+=right_move;
            right_ball+=boxes[index]-'0';
            right_move+=right_ball;
        }
        return ans;
    }
};