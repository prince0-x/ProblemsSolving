class Solution {
public:
   int solve(vector<int>&arr, int i , int currsum, int target){
    if(i == arr.size()){
       return currsum==target?1:0;
    }
    int add = solve(arr, i+1, currsum+arr[i], target);
    int subtract = solve(arr, i+1, currsum-arr[i], target);
    return add+subtract;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};