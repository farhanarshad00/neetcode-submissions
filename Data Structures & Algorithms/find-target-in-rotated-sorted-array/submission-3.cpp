class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while(low <= high){
            mid = (high + low) / 2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[low] > nums[mid]){ // Left half isn't sorted
                if(target > nums[mid] && target <= nums[high]){//Right half is sorted and target lives in [mid+1,high]
                    low = mid + 1;
                }else{// Target lives in the left half
                    high = mid - 1;
                } 
            }else{
                if(target < nums[mid] && target >= nums[low]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
            
        }
        return -1;
        
    }
};

/*
* What is known:
* The target may or may not be present in the array.
* All elements in the array are unique.
* The number of rotations k is between [1 and n] where n is the length of the array.
* A rotated array can be thought of as two sorted arrays joined together.
* The middle element in the array is not always the split point.
* The array passed in as a parameter is the sorted array.
*
* Approach: Binary Search half of an array
* Initialize two elements low and high that are the first and last index of the whole array.
* While (low <= high), we want to find the element that marks the beginning and end of each sorted sub-array within the array.
*   Calulate mid as (high + low) / 2.
*   If (nums[low] >= nums[mid]): Then the sorted array is in the right half.
*       Check if target == nums[low]: if so return low, if not set low = mid.
*   If (nums[high] <= nums[mid]): Then the sorted array is in the left half.
*       Check if nums[high] == target: if so return high, if not set high = mid.
* If the loop runs without executing return -1.
*/
