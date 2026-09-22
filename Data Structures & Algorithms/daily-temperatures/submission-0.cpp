class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> idxs;
       

        for(int i=0; i<n; i++){
            if(idxs.empty()){
                idxs.push(i);
            }else{
                if(temperatures[i]>temperatures[idxs.top()]){
                    while(idxs.empty() != true && temperatures[i]>temperatures[idxs.top()]){
                        result[idxs.top()]=(i-idxs.top());
                        idxs.pop();
                    }
                    idxs.push(i);
                }else{
                    idxs.push(i);
                }
            }
        }
        if(idxs.empty()){
            return result;
        }else{
            while(idxs.empty() != true){
                result[idxs.top()]=0;
                idxs.pop();
            }
        }

       
       return result; 
    }
};
/*
* What is known:
* For every index i, there needs to be a tracker running that counts the days until the next highest temperature 
* such that temperatures[i]<temperatures[i+j].
* At temperatures[0],i=0 there needs to be a variable holding temperatures[0] as the running max 
* and a counter to count how many days between 0 and j where temperatures[0]=r_max.
* When we get to an i s.t. temperatures[i]>temperatures[0] update r_max=temperatures[i].
* However, every index needs a counter counting the days between temperatures[i] and temperatures[i+j] 
* where temperatures[i+j]>temperatures[i].
* Since every index has a value of days between itself and the next WARMER day every index will need to have a counter running.
* Additionally every index will need a pointer to its value checking if a temperature greater than it has been reached.
* Each index would need to traverse the vector and compare each value to itself which would be an O(n^2) time complexity
* 
* Approach: Store running indices in stack 
* Create an vector<int> of the same size as temperatures, a stack<int> indices, and an int r_max
* Loop through temperatures  
* Check if indices.empty():
*   if so push i on to the stack;
*   if not check if temperatures[i]>temperature[indices.top]: 
*       if so push i-indices.top to result, pop indices.top() and redo until the stack is empty;
*       if not push i to the stack
* After the loop check if the stack is empty:
*   if so return result;
*   if not then set a loop while(indices.empty() != true):
*       set result[indices.top()] to 0 and pop
* Return result
*/