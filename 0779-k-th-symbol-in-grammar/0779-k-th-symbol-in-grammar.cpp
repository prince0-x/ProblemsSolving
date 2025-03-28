class Solution {
public:
    string solve(int n){
        if(n==0)return "0";
        string ans= solve(n-1);
        string rev = "";
        for(auto x:ans){
            if(x=='0'){
                rev+='1';
            }else{
                rev+='0';
            }
        }
        return ans+rev;
    }
    int kthGrammar(int n, int k) {
        int low =1, high=(1<<(n-1));
        int curr=0;
        while(low!=high)
        {
            int mid = (low+high)/2;
            if(k<=mid)
            {
                high = mid;
            }else{
                low=mid+1;
                curr =!curr;
            }
        }
        return curr;
    }
};