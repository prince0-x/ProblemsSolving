class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        
        int ans = 0;
        int p1 = 2;
        int p2 = 1;
        
        for (int i = 2; i < n; ++i)
        {
            ans = p1 + p2;
            p2 = p1;
            p1 = ans;
        }
        
        return p1;
    }
};