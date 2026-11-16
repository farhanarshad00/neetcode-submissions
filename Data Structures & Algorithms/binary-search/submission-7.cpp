class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        if(low == high){
            if(nums[low] == target){
                return low;
            }else{
                return -1;
            }
        }
    
        while(low <= high){
            mid = (high + low) / 2;

            if(target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                low = mid + 1;
            }else if(target < nums[mid]){
                high = mid - 1;
            }
        }
        return -1;      
    }
};

/*
* Approach: Binary Search
* Initialize two variables low and high equal to the first and last index in nums.
* While (low < high):
*   Calculate mid = (high + low) / 2
*   See if target == nums[mid]: if so return mid.
*   If target > nums[mid]: Set low = mid + 1.
*   If target < nums[mid]: Set high = mid - 1.
* If the loop runs fully then return -1.
*/