class Solution {
public:
 using ll = long long;
    char processStr(string s, long long k) {
        int n = s.size();
        ll len =0;
        for(auto &c:s){
            if(c=='*'){
                len = max(len-1, 0LL);
            }else if(c=='#'){
                len*=2;
            }else if(c!='%'){
                len++;
            }
        }
        if(k>=len) return '.';
        for(int i=n-1; ;i--){
            switch(s[i]){
                case '*':
                    len++;
                    break;
                case '#':
                    if(k>=len/2){
                        k-=len/2;
                    }
                    len/=2;
                    break;
                case '%':
                    k= len-1-k;
                    break;
                default:
                    if(len==k+1){
                        return s[i];
                    }
                    len--;
            }
        }
    }
};