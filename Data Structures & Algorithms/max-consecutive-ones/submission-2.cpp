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
* 2. If so increment count. 
* 3. When nums[i]=0 compare to max count
* 4. If max_count < count, set max_count = count.
* 5  Then reset the count.
* 
* 
*/