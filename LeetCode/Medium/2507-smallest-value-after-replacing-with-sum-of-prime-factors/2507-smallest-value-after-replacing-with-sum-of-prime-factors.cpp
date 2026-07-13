class Solution {
public:
int prime(int n){
    int ans=0;
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            ans+=i;
            n/=i;
        }
    }
    if(n>1)ans+=n;
    return ans;
}
    int smallestValue(int n) {
        int prev=n;
        n=prime(n);
        while(n!=prev){
            prev=n;
            n=prime(n);
        }
        return n;
    }
};