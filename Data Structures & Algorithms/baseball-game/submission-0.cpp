class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int total = 0;
   
        for(const auto& it : operations){
           if(it=="+"){
                int addend1 = scores.top();
                scores.pop();
                int addend2 = scores.top();
                scores.push(addend1);
                int addsum = addend1+addend2;
                scores.push(addsum);
            }else if(it=="D"){
                int dub = 2* scores.top();
                scores.push(dub);
            }else if(it=="C"){
                scores.pop();
            }else{
                int num = stoi(it);
                scores.push(num);
            }
        }
        while(scores.empty() != true){
            total = total + scores.top();
            scores.pop();
        }
    return total;    
    }
};

/*
* Approach: Loop through vector and convert into operations for stack.
* 1. Initialize stack called scores and int variable total set to 0
* 2. Traverse through input vector and push element onto stack if its a digit
* 3. Otherwise check if element matches operation and perform operation on stack
* 4. After traversing vector, aggregate all elements in stack using a while loop
* 5. return total
*/