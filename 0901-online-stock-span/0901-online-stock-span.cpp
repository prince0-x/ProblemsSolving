class StockSpanner {
public:
stack<pair<int, int>>s;
int index = -1;
    StockSpanner() {
        
    }
    
    int next(int price) {
        index +=1;
        while(!s.empty() && s.top().second<=price){
            s.pop();
        }
        if(s.empty()){
            s.push({index, price});
            return index+1;
        }
        int ans = s.top().first;
        s.push({index, price});
        return index-ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */