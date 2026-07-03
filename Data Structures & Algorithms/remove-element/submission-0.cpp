class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
    return k;
    }
};

/*
* Approach: Loop based solution 
* 1. Loop through the vector finding when nums[i]!=val
* 2. If nums[i]!=val increment k
* 3. If nums[i]==val
*/