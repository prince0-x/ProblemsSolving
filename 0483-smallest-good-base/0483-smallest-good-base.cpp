class Solution {
public:

    long long  solve(long long number,long long  dig, long long  mid){
        long long  temp= 1;
        long long  x =1;
        for(long long  j =1; j<dig; j++){
            if(x >(number-temp)/mid)return LLONG_MAX;
            x*=mid;
            temp+=x;
        }
        return temp;
    }
    string smallestGoodBase(string n) {
        long long number = stoll(n);
        for(int i =63;i>1;i--){
            long long low =2, high = number-1;
            while(low <= high){
                long long  mid =(low+high)/2;
                long long  cr = solve(number, i, mid);
                if(cr == number)return to_string(mid);
                if(cr < number){
                    low=mid+1;
                }else{
                    high = mid -1;
                }
            }
        }
        return to_string(number-1);
    }
};