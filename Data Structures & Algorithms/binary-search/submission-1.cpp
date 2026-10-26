class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (high + low) / 2;

        while(low != high){
            if(nums[mid]<target){
                low = mid + 1;
                mid = (high + low) / 2;
            }else if(nums[mid] > target){
                high = mid;
                mid = (high + low) / 2;
            }else{
                return mid;
            }
        }
        if(nums[low] == target){
            return low;
        }
        return -1;
        
    }
};

/*
* Approach: Binary Search Algo
* Initialize 3 variables low and high to represent the bounds of the search.
* Initialize a variable mid that is the middle of the search range.
* While low < high: 
*   check if nums[mid] < target: if so set low = mid + 1 and recalculate mid.
*   else if nums[mid] > target: set high = mid and recalculate mid.
*   else if nums[mid] == target: return mid
* If the loop runs without finding the index return -1.
*/