class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int planted =0, n1 = f.size();
        for(int i=1; i<n1; i++)
        {
            if(f[i-1] ==0 and f[i+1]==0)planted++;
            continue;
        }
        return (n-planted)==0;
    }
};