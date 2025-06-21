class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1), pge(n, -1), ans(n, -1);
        stack<int> s;

  
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nge[i] = s.top();
            }
            s.push(nums[i]);
        }

        s = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pge[i] = s.top();
            }
            s.push(nums[i]);
        }

        for(int i=0;i<n;i++){
            if(nge[i]!=-1){
                ans[i]= nge[i];
            }else if(pge[i]!= -1){
                ans[i]= pge[i];
            }
        }
        return ans;

    }
};