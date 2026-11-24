class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;

        while(low <= high){
            mid = (high + low) / 2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[low] <= nums[mid]){// left side is sorted
                if(nums[low] <= target && nums[mid] > target){// target is in the left side
                    high = mid - 1;
                }else{//target is in the right side
                    low = mid + 1;
                }
            }else{// right side is sorted
                if(nums[mid] < target && target <= nums[high]){//target is in the right side
                    low = mid + 1;
                }else{// target is in the left side
                    high = mid - 1;
                }

            }
        }
        return -1;
        
    }
};

/*
* What is known:
* # of rotations k is between [1,n].
* The target may or may not be present in the array.
* All elements in nums are unique.
* Rotating a sorted array results in an array made up of two sorted subarrays.
* The pivot point might not be in the middle element of the array.
* We can figure which side is sorted by checking if nums[low] < nums[mid]. If true then the left side is sorted, if not then the right side is sorted.
*   Check if the target lives in the sorted left side: if so set high = mid - 1 and if not set low = mid + 1.
*   Vice versa if the right side is sorted.
*/