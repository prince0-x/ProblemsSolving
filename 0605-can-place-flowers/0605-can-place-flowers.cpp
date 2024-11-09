class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int planted =0, n1 = f.size();
        if(n1==1 and f[0]==0 and n1<=1)return true;
        if(f[0]==0 and f[1]==0){
            f[0]=1;
            planted++;
        }
        for(int i=1; i<n1-1; i++)
        {
            if(f[i-1] ==0 and f[i+1]==0 and f[i]==0){
                planted++;
                f[i]=1;}
            
        }
        if(f[n1-1]==0 and f[n1-2]==0){
            f[n1-1]=1;
            planted++;
        }
        return planted>=n;
    }
};