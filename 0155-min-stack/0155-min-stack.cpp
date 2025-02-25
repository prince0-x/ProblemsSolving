class MinStack {
public:
    stack<pair<int,int>>s;
    int mini = getMin();
    MinStack() {
        
    }
    
    void push(int val) {
        mini = getMin();
        if(s.empty() || mini > val)
        {
            mini = val;
        }
        s.push({val,mini});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.empty() ? -1 : s.top().first;
    }
    
    int getMin() {
        return s.empty() ? -1 : s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */