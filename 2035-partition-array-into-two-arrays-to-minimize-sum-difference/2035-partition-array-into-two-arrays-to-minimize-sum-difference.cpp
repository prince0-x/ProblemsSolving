class Solution {
public:
int ans = INT_MAX;
void solve( vector<int>&nums,int size, int index, int count, int sum,vector<vector<int>>&dp)
{

    if(index == size ){
        dp[count].push_back(sum);
        return;
    }
    solve(nums,size, index+1,count, sum, dp );
    solve(nums, size, index+1, count+1, sum+nums[index], dp);
}
    int minimumDifference(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int m = nums.size();
        int n = m/2;
        vector<vector<int>>d1(n+1),d2(n+1);
        
        solve(nums, n, 0, 0, 0, d1);
        solve(nums, m, n, 0, 0, d2);

        for(auto& i:d2){
            sort(i.begin(), i.end());
        }
        for(int i =0;i<=n;i++)
        {
            
            for(int j =0;j<d1[i].size();j++)
            {
               int s1 = d1[i][j];

               int low = 0;
               int high = d2[n-i].size()-1;
               while(low<=high)
               {
                int mid = (low+high)/2;
                int s2 = d2[n-i][mid];
                ans = min(ans,abs (total -2*(s1+s2)));

                if(total>2*(s1+s2))low = mid+1;
                else high = mid-1;
               }   
            }
        }


       
        return ans;
    }
};