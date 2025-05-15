class Solution {
public:
    int carFleet(int target, vector<int>& arr, vector<int>& speed) {
        vector<pair<int, double>>position;
        for(int i =0;i<arr.size(); i++){
            position.push_back({target -arr[i], ((target-arr[i])/(1.0*speed[i]))});
        }
        sort(position.begin(), position.end());

    
    int cnt =0, val=-1;
    for(int i=0;i<position.size(); i++)
    {
        if(position[i].second >val){
            val = position[i].second;
            cnt++;
        } 
    }
    return cnt;
    }
};