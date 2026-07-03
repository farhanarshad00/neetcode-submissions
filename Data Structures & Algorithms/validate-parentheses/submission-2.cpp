class Solution {
public:
    bool isValid(string s) {
        stack<char> brkets;
        int n = s.length();
        

        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                brkets.push(s[i]);
            }else if(s[i]==')'){
                if(brkets.empty()){
                    return false;
                }else if (brkets.top()=='('){
                    brkets.pop();
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                if(brkets.empty()){
                    return false;
                }else if(brkets.top()=='{'){
                    brkets.pop();
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                if(brkets.empty()){
                    return false;
                }else if(brkets.top()=='['){
                    brkets.pop();
                }else{
                    return false;
                }
            }
        }
        if(brkets.empty()){
            return true;
        }
    return false;   
    }
};

/* 
* Approach: Use loop to traverse through input and add suitable elements to stack
* 1. Create a stack of chars called brkets
* 2. Loop through elements of input string
* 3. Add on to stack if bracket type is open
* 4. Pop from stack if bracket type is corresponding with brkets.top()
* 5. If element is a closing bracket with no corresponding opening bracket return false
*/