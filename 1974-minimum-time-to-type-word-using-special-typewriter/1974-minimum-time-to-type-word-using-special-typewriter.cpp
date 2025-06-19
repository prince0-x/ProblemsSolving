class Solution {
public:
    int minTimeToType(string w) {
            int dist = abs(w[0] - 'a');
            int minSteps = min(dist, 26 - dist);
            int ans=minSteps+1;
            
        for(int i=1;i<w.size();i++){
            int w1= int(w[i-1]-'a'+1);
            int w2= int(w[i]-'a'+1);
            dist = abs(w2 - w1);
            minSteps = min(dist, 26 - dist);
            ans+=minSteps+1;
        }
        return ans;
    }
};