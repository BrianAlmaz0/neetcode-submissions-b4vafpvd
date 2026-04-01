class MinStack {
public:
    //Key: Val, Value: MinVal
    vector<pair<int, int>> stk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push_back({val, val});
        } else{
            stk.push_back({val, min(val, stk.back().second)});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
