class Solution {
public:
    int subarraySum(vector<int>&a, int k) {
    int n = a.size(),cnt=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==k){
                cnt++;
            }
        }
    }
    return cnt;
    }
};