class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(min_stk.empty()){
            min_stk.push(val);
        }else if(val<min_stk.top()){
            min_stk.push(val);
        }else{
            int min = min_stk.top();
            min_stk.pop();
            min_stk.push(val);
            min_stk.push(min);
        }
        stk.push(val);
    }
    
    void pop() {
        if(stk.top()==min_stk.top()){
            stk.pop();
            min_stk.pop();
        }else{
            int min = min_stk.top();
            min_stk.pop();
            min_stk.pop();
            stk.pop();
            min_stk.push(min);
        }
        
        
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
