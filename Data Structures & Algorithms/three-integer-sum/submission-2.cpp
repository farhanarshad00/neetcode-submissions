class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> sol_vec;
        

        for(int i=0; i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            vector<int> inner(3);
            int l_ptr = i+1;
            int r_ptr = (nums.size()-1);
            int sum = 0;
            while(l_ptr < r_ptr){
                sum = nums[l_ptr] + nums[i] + nums[r_ptr];

                if(sum==0){
                    inner[0]=nums[i];
                    inner[1]=nums[l_ptr];
                    inner[2]=nums[r_ptr];
                    sol_vec.push_back(inner);
                    
                    l_ptr++;
                    while(l_ptr<r_ptr && nums[l_ptr]==nums[l_ptr-1]){
                        l_ptr++;
                    }
                    r_ptr--;
                    while(r_ptr>l_ptr && nums[r_ptr]==nums[r_ptr+1]){
                        r_ptr--;
                    }
                    
                }else if(sum<0){
                    l_ptr++;
                }else if(sum>0){
                    r_ptr--;
                }
            }

            
        }
                
            

        
        return sol_vec;
        
    }
};

/*
* Approach: Two pointers tracking elements per iteration
* Sort nums in ascending order
* Initialize a vector<vector<int>> sol_vec
* Loop through nums from i=0 to i=nums.size()-3
* Initialize 2 pointers: l_ptr=0 r_ptr=nums.size()-1
* Check if i>0 && nums[i]==nums[i-1]:if so use continue to skip current iteration and move on to the next one;
* While (l_ptr<r_ptr) initialize a vector<int> inner(3) and sum the values of nums[l_lptr], nums[i], nums[r_ptr]
* Check if sum==0: if so set inner[0]=nums[l_ptr],inner[1]=nums[i],inner[2]=nums[r_ptr] to inner vector and push back inner to sol_vec
*   Increment l_ptr then while(nums[l_ptr]==nums[l_ptr-1]) increment l_ptr
*   Decrement r_ptr then then while (nums[r_ptr]==nums[r_ptr+1]) decrement r_ptr
* else if sum<0: increment l_ptr
* else if sum>0: decrement r_ptr
* After the loop return sol_vec
*/