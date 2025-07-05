class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int>m;
        for(int &i:arr){
            m[i]++;
        }
        for(auto [k,v]:m){
            if(k==v)return k;
        }
        return -1;
    }
};