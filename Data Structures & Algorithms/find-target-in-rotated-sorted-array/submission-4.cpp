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
* While (low <= high), we want to find which half of the array is sorted.
*   Calulate mid as (high + low) / 2.
*   If nums[mid] == target: return mid.
*   If (nums[low] > nums[mid]): Then the left half isnt sorted.
*       Check if the target is > nums[mid] and < nums[high]: if so the target is in [mid+1,high] so set low = mid +1.
*           If not the target is in the left half so set high = mid - 1.       
*   Else the right half isn't sorted.
*       Check if the target is < nums[mid] && >= nums[low]: if so the target is in [low,mid-1] so set high = mid - 1.
*           If not the target is in the right half so set low = mid + 1.
* If the loop runs without executing return -1.
*/
