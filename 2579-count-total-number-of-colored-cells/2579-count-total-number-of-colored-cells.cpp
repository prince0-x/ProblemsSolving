class Solution {
public:
    long long coloredCells(int n) {
        long long ans=0;
        ans+=2*n-1;
        n--;
        while(n>0)
        {
            ans+=2*(2*n-1);
            n--;
        }
        return ans;
    }
};