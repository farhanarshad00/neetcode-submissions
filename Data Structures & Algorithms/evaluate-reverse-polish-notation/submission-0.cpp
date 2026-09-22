class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> opstk;
        int dummy1 = 0;
        int dummy2 = 0;
        int dummyeval;
        string dumtok;
        int sol;

        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                dummy1 = stoi(opstk.top());
                opstk.pop();
                dummy2 = stoi(opstk.top());
                opstk.pop();

                dummyeval = dummy2+dummy1;
                dumtok = to_string(dummyeval);
                opstk.push(dumtok);


            }else if(tokens[i]=="-"){
                dummy1 = stoi(opstk.top());
                opstk.pop();
                dummy2 = stoi(opstk.top());
                opstk.pop();
                dummyeval = dummy2-dummy1;
                dumtok = to_string(dummyeval);
                opstk.push(dumtok);

            }else if(tokens[i]=="*"){
                dummy1 = stoi(opstk.top());
                opstk.pop();
                dummy2 = stoi(opstk.top());
                opstk.pop();
                dummyeval = dummy2*dummy1;
                dumtok = to_string(dummyeval);
                opstk.push(dumtok);

            }else if(tokens[i]=="/"){
                dummy1 = stoi(opstk.top());
                opstk.pop();
                dummy2 = stoi(opstk.top());
                opstk.pop();
                dummyeval = dummy2/dummy1;
                dumtok = to_string(dummyeval);
                opstk.push(dumtok);

            }else{
                opstk.push(tokens[i]);
            }
        }
    sol = stoi(opstk.top());
    return sol;   
    }
};
/*
* Approach: Stack tracking operands and operators
* Create a stack<string> opstk and a stack<int> evstk
* Loop through the string tokens 
*   Check if tokens[i] is an integer: 
*       if so push it to the stack;
*       if not use a dummy int to store the stk.top()=char representing an integer as an int,
*        then pop it from the stack, repeat for the next stk.top() and find the evaluation of the expressionthen push it into evstk 
*/