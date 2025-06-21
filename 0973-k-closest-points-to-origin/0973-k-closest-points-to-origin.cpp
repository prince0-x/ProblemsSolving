class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const pair<double, pair<int, int>>& a,
                  const pair<double, pair<int, int>>& b) {
        return a.first > b.first; 
    };

    priority_queue<
        pair<double, pair<int, int>>,
        vector<pair<double, pair<int, int>>>,
        decltype(cmp)
    > pq(cmp);

    for (auto& point : points) {
        int x = point[0];
        int y = point[1];
        double distance = sqrt(x * x + y * y);
        pq.push({distance, {x, y}});
    }
    vector<vector<int>>ans;
    int i=0;
    while(i<k){
        auto a = pq.top();
        pq.pop();
        ans.push_back({a.second.first, a.second.second});
        i++;
    }
    return ans;
    }
};