class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
      
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
                max_count = max(max_count,count);
            }else if(nums[i]==0){
                count = 0;
            }
        }

    return max_count;
        
    }
};

/*
* Approach: 
* 1. Loop through vector and check if nums[i] is 1. 
* 2. If so increment count and compare it to max_count. 
* 3. When nums[i]=0 reset the count.
* 4. return max_count
* 
* 
*/