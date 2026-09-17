class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> sol_vec;
        int l_ptr = 0;
        int r_ptr = numbers.size()-1;
        int sum = 0;

        while(l_ptr < r_ptr){
            sum = numbers[l_ptr] + numbers[r_ptr];

            if(sum == target){
                sol_vec.push_back(l_ptr+1);
                sol_vec.push_back(r_ptr+1);
                break;
            }else if(sum < target){
                l_ptr++;
            }else if(sum > target){
                r_ptr--;
            }
        }
        return sol_vec;
        
    }
};

/*
* Approach: Use two pointers to compute sum of elements
* Initialize a vector<int> sol_vec that will contain the 1-indexed solution indices
* Initialize int l_ptr=0 and int r_ptr=numbers.size() 
* which represent the beginning index and end index of numbers respectively
* While (l_ptr<r_ptr) sum numbers[l_ptr] and numbers[r_ptr]
* Check if sum == target: 
*   if so do sol_vec.push_back(l_ptr) and sol_vec.push_back(r_ptr);
*   else if sum < target: increment l_ptr
*   else if sum > target: decrement r_ptr
* Return sol_vec
* 
*  
*/