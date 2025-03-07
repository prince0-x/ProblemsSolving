class Solution {
public:
    double myPow(double a, int b) {
        if(b<0)
        {
            return 1 / a * double(1.0)/myPow(a,-(b + 1));
        }
        if(b==0)return 1;
        if(b==1)return a;
       double x = myPow(a,b/2);
       x*=x;
       if(b%2==1) return x*a;
       return x;
    }
};