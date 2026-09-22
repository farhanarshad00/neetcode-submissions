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
* Create a stack<string> opstk 
* Loop through the string tokens 
*   Check if tokens[i] is any of the operands: 
*       if so convert the two top values in the stack into ints,pop each from the stack, evaluate the operation, 
*           convert the evaluated result to a string and push it back to the stack;
*       if not push it onto the stack
*/