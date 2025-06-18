class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if (r * c != n * m) return mat;
        vector<int>arr(m*n);
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                arr[n*i+j] = mat[i][j];
            }
        }
        vector<vector<int>>mat2(r, vector<int>(c));
        for(int i = 0;i<arr.size();i++){
            mat2[i/c][i%c] = arr[i];
        }
        return mat2;
    }
};