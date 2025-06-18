class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        vector<int>temp = ans;
        if(rowIndex == 0)return ans;

        for(int i =1;i<=rowIndex;i++){
            for(int j =1; j<temp.size(); j++){
               temp[j] = ans[j]+ans[j-1];
            }
            if(i>0){
                temp.push_back(1);
            }
            ans= temp;
        }
        return ans;
    }
};