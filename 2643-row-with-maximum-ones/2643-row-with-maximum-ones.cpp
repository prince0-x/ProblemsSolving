class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int R = mat.size();
        int C = mat[0].size();
        vector<int>count(R,0);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[i][j] == 1) {
                    count[i]++;
                }
            }
        }
        int row=-1, val=-1;
        for(int i=0;i<R;i++){
            if(count[i]>val){
                val=count[i];
                row=i;
            }
        }
        return {row, val};
    }
};