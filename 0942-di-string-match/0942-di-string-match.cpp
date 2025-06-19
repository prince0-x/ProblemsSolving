class Solution {
public:
    vector<int> diStringMatch(string s) {
        int val=0;
        vector<int>arr(s.size()+1);
        for(int i =0;i<s.size();i++){
            if(s[i]=='I'){
                arr[i] = val;
                val++;
            }
        }
        arr.back()=val;
        val++;
        for(int i= s.size()-1; i>=0;i--){
            if(s[i] =='D'){
                arr[i]=val;
                val++;
            }
        }
        return arr;
    }
};