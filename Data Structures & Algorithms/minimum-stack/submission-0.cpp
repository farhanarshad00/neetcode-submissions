class MinStack {
private: 
    stack<int> stckobj;
    stack<int> minst;
public:
    MinStack() {}
    
    void push(int val) {
       stckobj.push(val);
       if(minst.empty()){
            minst.push(val);
        }else{
            minst.push(min(val,minst.top()));
        }
        
    }
    
    void pop() {
       stckobj.pop();
       minst.pop();
    }
    
    int top() {
        
        int topval = stckobj.top();
        return topval;
        
    }
    
    int getMin() {
        return minst.top();
        }
};

/*
* Approach: Temporary Array copy of stack
* 1. Initialize two stacks as member variables, one for regular operations and one tracking the minimum value
* 2. For push() function, push value to regular stack and push the minimum value between (val,minst.top()) to ensure both stacks have the same size
* 3. For pop() function, pop values from both stacks so that they remain the same size
* 4. Fill in top function for regular stack variable
* 4. For getMin() return top of minst
*/
