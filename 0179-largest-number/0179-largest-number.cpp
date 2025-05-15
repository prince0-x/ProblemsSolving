class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){
            
    string s1 = to_string(a);
    string s2= to_string(b);
    return (s1+s2)>(s2+s1);
});
        string ans="";
        for(auto i:nums){
            ans+=to_string(i);
        }
        int i =0;
        while(i<ans.size()-1 && ans[i]=='0'){
            i++;
        }
        return ans.substr(i);
    }
};