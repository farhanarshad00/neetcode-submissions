class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while(low <= high){
            mid = (high + low) / 2;

            if(target == nums[mid]){
                return mid;
            }

            if(nums[low] <= nums[mid]){
                if(target > nums[mid] || target < nums[low]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }else{
                if(target < nums[mid] || target > nums[high]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            
        }
        return -1;
    }
};

/*
* What is Known:
* If k = n then the array returns to its original form.
* k is between [1,n].
* All nums[i] are unique integers.
* Unlike Minimum in Rotated Sorted Array the target might not be in the array.
* After rotation the array can be represented as two chunks: original array size = chunk 1 size + chunk 2 size.
* Both chunks are sorted in ascending order.
* For example with k = 4: chunk 1 = {3,4,5,6} and chunk 2 = {1,2}. 
* Placing chunk 1 after the last element of chunk 2 yields the original array.
*
* Approach: Binary Search(One Pass) From Neetcode Official Solution
* 
* 
*/